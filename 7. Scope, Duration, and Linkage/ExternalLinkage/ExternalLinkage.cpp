// external linkage means variables can be accessed by other files

// in this context, extern means give this variable external linkage

// non-const global variables should only represent one thing and should be 
// ubiquitous across program
int g_a {2};  // global variables are external by default
extern const int g_b {3};  // use "extern" keyword to make const vars external
// cannot forward declare this, thus this usage of extern constexpr is useless
extern constexpr int g_c {3};  // use "extern" to make constexpr vars external

// non const
int g_x;  // variable definition (w/o initialization)
// avoid using extern keyword on non const global vars with initializer (compiler warning)
int g_y {1};  // variable definition (w/ initialization)

// Note: don't use the keyword extern and no initializer as compiler will think
// this is forward declaration even if you meant to define it here
extern int g_x;  // forward declaration

// const
extern const int g_z {1};  // variable definition
// const requires initializer so you don't have to worry about above note for them
extern const int g_z;  // forward declaration

