class Base
{
    public:
    int m_public{};  // can be accessed by anybody
    protected:  // while protected is good, favor private with protected/public interface
    int m_protected{};  // can be accessed by Base members, friends, and derived classes
    private:
    int m_private{};  // can only be accessed by Base members and friends
};

class Derived : public Base
    // Public Inheritance:
    // Public Inherited Members stay public
    // Protected Inherited Members stay protected
    // Private Inherited Members stay private (inaccessible)
    //
    // General Rule of Thumb: Use Public Inheritance unless specific reason to not
{
    public:
    Derived()
    {
        m_public = 1;  // allowed: can access public members of parent
        m_protected = 1;  // allowed: can access protected members of parent
        // m_private = 1;  // not allowed: cannot access private members of parent
    }
};

class Prot : protected Base
{
    // Public and Protected members from Base are Protected, Private is 
    // still Private (inaccessible)
    // Very Rare
};

class Priv : private Base
{
    // Public and Protected members from Base become Private (accessible in this class only now)
    // Private is still Private (inaccessible)
};

class Pub : public Priv
{
    // Pub can access public and protected members from Priv, not private members
    // Pub cannot access any members from Base since Priv made them all private
    // Pub can have its own public, private, protected members
};

auto main() -> int
{
    Base base;
    base.m_public = 1;  // allowed: can access public members from outside of class
    // base.m_protected = 1;  // not allowed: cannot access protected members outside of class
    // base.m_private = 1;  // not allowed: cannot access private members outside of a class
    
    Derived derived;
    derived.m_public = 1;  // allowed: public Inheritance keeps public
    // derived.m_protected = 1;  // not allowed: public Inheritance keeps protected
    // derived.m_private = 1;  // not allowed: public Inheritance keeps private
    

    return 0;
}
