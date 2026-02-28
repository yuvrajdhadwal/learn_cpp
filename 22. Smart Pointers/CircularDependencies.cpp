#include <iostream>
#include <memory>
#include <string>

class Person {
    std::string m_name;
    // std::shared_ptr<Person> m_partner;  // initially created empty
    std::weak_ptr<Person> m_partner;  // weak_ptr sees value, but doesn't increase ref count

   public:
    Person(const std::string& name) : m_name{name} { std::cout << m_name << " created!\n"; }

    ~Person() { std::cout << m_name << " destroyed\n"; }

    friend bool partnerUp(std::shared_ptr<Person>& p1,
                          std::shared_ptr<Person>& p2)  // this creates circular dependency
    {
        if (!p1 || !p2) {
            return false;
        }

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

        return true;
    }

    std::shared_ptr<Person> getPartner() const {
        if (m_partner.expired()) {
            return nullptr;
        }
        return m_partner.lock();
    }  // use lock() to convert weak to shared ptr; lock() on expired weakptr returns sharedptr to nullptr
    const std::string& getName() const { return m_name; }
};

auto main() -> int {
    auto lucy{std::make_shared<Person>("Lucy")};
    {
        auto ricky{std::make_shared<Person>("Ricky")};

        partnerUp(lucy, ricky);

        auto partner = ricky->getPartner();  // get shared pointer to rickys partner
        std::cout << ricky->getName() << "'s partner is " << partner->getName() << '\n';
    }
    std::cout << lucy->getPartner()->getName();  // this causes a seg fault since weakptr is
                                                 // dangling at this point, this is why we need to
                                                 // check if weakptr is expired
    return 0;
}
