//////////////////////////////////////////////////////////////////////////////
//C++ NOTES
//////////////////////////////////////////////////////////////////////////////
/*

unsigned char         BYTE        ---
short                 ---         short int / signed short / signed short int
unsigned short        WORD        unsigned short int
int                   INT/BOOL    signed 
unsigned int          UINT        unsigned
long                  ---         long int / signed long / signed long int
unsigned long         ULONG       unsigned long int
long long             ---         long long int / signed long long / signed long long int
unsigned long long    DWORD       unsigned long long int
float                 FLOAT       ---

VALUE-TYPE VARIABLES
• Any variable stored on stack, includes pointer/reference to another variable
• Memory managed by stack and deleted when out of scope

REFERENCE-TYPE VARIABLES
• Any variable stored on heap, requires new to create
• Memory managed by heap, requires user to delete if not referenced counted

STATIC VARIABLES
• Static typed variables: class members, local or global variables
• Class members initialised to 0 or given value from class .cpp before main called
• Global/Local initialised to 0 until first use then re-initialised to given value when used
• Global variables: don't require static keyword to be static typed (keyword determines linkage)
• Static const variables: if type is known may be replaced throughout program as macro

TEMPORARY VARIABLES
• Move semantics reduces creation of temp variables
• Value-typed variables auto created on the stack during:
   - reference initialization
   - expression evaluation
   - automatic type conversion
   - function passing/returning

CONST VARIABLES
• If type is known and only used as a literal variable, replaced as a macro at compile time
• If type unknown or is refered to, may be stored in fixed seperate memory/data segment
• Variable const-casted remains in same location but cannot change values
• Pros: Using const allows both const and non-const objects to use a method
• Pros: Using const protects you against accidently editing data
• Cons: Usage must be maintained otherwise useless
• Cons: Hard to tell if variable is const stored in seperate memory or just const casted

OPERATORS
%  Remainder whole number after how many x is in y
:: Scope resolution operator

SEQUENCE POINTS
• Undefined behaviour when changing a variable and reading it again without a sequence point.
• After a function's returned object has been copied back to the caller
• After evaluation of all a function's parameters when the function is called
• After the initialization of each base and member for an object
;       int x = 0;
,       f(x,y) 
||      x || y 
&&      x && y 
?:      x ? y : 0 

//////////////////////////////////////////////////////////////////////////////
//MOVE SEMANTICS
//////////////////////////////////////////////////////////////////////////////

• Allows resources to transfer between objects rather than copying
• Automatically done when passing variables by-val for stl/conatiner/values
• STL containers no longer copy values when expanding; moves values via pointers
• Required for unique pointer (which can't be copied) usage in STL containers

                                EXPRESSION
                                /        \
                            GLVALUE    RVALUE
                            /     \    /    \
                        LVALUE    XVALUE   PRVALUE

GLVALUE: L-value or X-value
LVALUE: Persisting; appears on left side of assignment expression
RVALUE: Temporary; appears on right side of assignment expression
XVALUE: Value that will expire soon (Rvalue reference function return)
PRVALUE: Rvalue that isn't an xvalue (Non-reference function return)

//////////////////////////////////////////////////////////////////////////////
//POINTERS
//////////////////////////////////////////////////////////////////////////////

VARIABLES/OBJECTS: &name gives address of object
C-STYLE ARRAY: name gives address of first element
CSTRING/STRING LITERAL: name gives string, &name gives address of first character

===========================================================================
POINTERS/REFERENCES DIFFERENCES
===========================================================================
• Pointers hold a memory address; reference is another name for variable.
• Pointer must be dereferenced, reference just uses name
• References can't change once initialised. Pointers can change what they point to.s
• References can't easily be nullptr or void, pointers can
• Multiple levels of Pointers, one level of reference
• Pointers use -> for classes/structures while references use .

===========================================================================
SMART POINTERS
===========================================================================

SHARED POINTER
• uses reference counting; when goes to 0, object is deleted
• supports copying/assigning/usage in STL containers
• can't detect cyclic dependencies

WEAK POINTER
• non-owning observers of an object owned by shared_ptr.
• does not use reference counting
• when object is deleted, all pointers are marked as invalid
• useful when having cyclic dependencies and in place of raw pointers

UNIQUE/SCOPED POINTER
• No sharing or reference counting
• can't be copied, only moved, can be used in stl containers due to move semantics
• when pointer goes out of scope, object deleted
• std::unique_ptr requires default destructor/constructor of class it 
  exists in if the pointer type is forward declared

INTRUSIVE POINTER
• Shared pointer where reference counting is not done by the pointer object
• Helper function is used which is defined by the object that is pointed to

AUTO POINTER
• has sole ownership of the object which is passed if the pointer is copied
• if copied the original is set to nullptr; passing by-ref is okay
• can't point to arrays due to it using delete, not delete []
• can't point to memory on the stack
• can't be used in STL containers due to it's transfer ownership property

ARRAY POINTERS
• boost scoped_array; Simple sole ownership of arrays. Noncopyable.
• boost shared_array; Array ownership shared among multiple pointers.

===========================================================================
NEW AND DELETE
===========================================================================
• Don’t use delete to free memory that new didn’t allocate.
• Don’t use delete to free the same block of memory twice in succession.
• Use delete [] if you used new [] to allocate an array.
• Use delete (no brackets) if you used new to allocate a single entity.
• It’s safe to apply delete to the null pointer (nothing happens).

PLACEMENT NEW:
• creates section of memory in stack
• can't use delete since its on the stack; deleted when goes out of scope
• for class: destructor must be explicitly called before it goes out of scope

////////////////////////////////////////////////////////////////////////////////////
//CLASSES/STRUCTS/FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////

ORDER OF ARGUMENT EVALUATION
Order that function parameters are evaluated is up to the complier.
callFunc(getA(),getB()); can either be:

  int a = getA();       int b = getB();
  int b = getB();  OR   int a = getA();
  callFunc(a,b);        callFunc(a,b);

STRUCTURE/CLASS DIFFERENCES: 
• Class members/inheritance is private by default
• Struct members/inheritance is public by default

==========================================================================
CLASS LIFETIME
==========================================================================
• Const members/References must be initialised through the initialisation list
• Don't call virtual methods in constructor; undefined behaviour; calls Base version
• Initialisation list doesn't reflect order of construction
• Static member variables initialised before program begins

1) Base Initialisation List called
2) Base Constructor Body called
3) Derived Initialisation List called
4) Derived Constructor Body called
5) Derived Destructor called
6) Base Desctructor called

DESTRUCTOR: Called when out of scope, delete used or explicitly
FINALISER: Called when object is garbage collected

==========================================================================
CONSTANT MEMBER
==========================================================================
• Invoked by const or non-const object
• Const objects can only call Const member functions
• Uses const 'this' pointer
• Must not edit parameters of function

CLASS BITWISE CONST CHECKING
occurs if function doesn't modify any class non-static members 
doesn't include what a member pointer points to or returned values
compilers check for this in functions to determine if const

==========================================================================
IMPLICIT MEMBER FUNCTIONS
==========================================================================
Created implictely if needed unless explicitely defined:
• Constructor
• Copy Constructor
• Destructor
• Assignment Operater
• Address Operator

When none of the above/below are explicitly created and are needed:
• Move Constructor
• Move Assignment Operator

==========================================================================
COPY-SWAP IDIOM
==========================================================================
• Used for assignment operator when doing a deep copy
• Requires non-throwing swap function, copy constructor and destructor
• Passes argument in by-val; if construction fails, 'this' never used in body
  which gives strong exception guarantee/avoids code duplication

//////////////////////////////////////////////////////////////////////////////
//INHERITANCE
//////////////////////////////////////////////////////////////////////////////

PUBLIC INHERITANCE: 
  Base class public     becomes   Derived class public
  Base class protected  becomes   Derived class protected
  Base class private    becomes   Not inherited

PROTECTED INHERITANCE:
  Base class public     becomes   Derived class protected
  Base class protected  becomes   Derived class protected
  Base class private    becomes   Not inherited

PRIVATE INHERITANCE:
  Base class public     becomes   Derived class private
  Base class protected  becomes   Derived class private
  Base class private    becomes   Not inherited

ALLOWS DERIVED CAST TO BASE:
  Public: Yes
  Protected/Private: No
  
--------------------------------------------------------
FUNCTION      INHERITED    IMPLICIT  VIRTUAL  RETURNS
--------------------------------------------------------
Constructors  No           Yes        No      No
Destructor    No           Yes        Yes     No
As.Operator   No           Yes        Yes     Yes
Operator&     Yes          Yes        Yes     Yes
Operator[]    Yes          No         Yes     Yes
Conversion    Yes          No         Yes     No (Yes)
Friends       No           No         Yes     -


VIRTUAL FUNCTIONS:
•  Allows derived method to be called for base class pointers/references
•  Can't be a template function as once the run-time system figured out it 
   would need to call a templatized virtual function, compilation is all 
   done and the compiler cannot generate the appropriate instance anymore
•  Visibility between Base/Derived doesn't have to match- determined and
   overriden by base class visibility

V-TABLE
•  Hidden member in each object created as pointer to an array of virtual 
   function addresses (Virtual Function Table (vtbl))
•  BaseClass Object holds initial virtual function addresses
•  DerivedClass Object holds initial and new virtual function addresses, 
   overwriting if any redefined
•  When virtual function called, VTBLE used to find the correct address
•  Constructors and Friends can't be virtual
•  Stores the classes's type_info object used for RTTI

PURE VIRTUAL/ABSTRACT BASE CLASS
•  Base class where a method is declared but not defined; pure virtual method

VIRTUAL BASE CLASS
•  Disallows mutiple copies of the base class when used in diamond shaped
   Multiple inheritance. Base class constructor must be explicitly called

RUN-TIME TYPE INDENTIFICATION (RTTI)
•  Allows determining type of derived class from a base class *
•  Only works on classes that use virtual methods as type_info stored in vtbl
•  Sometimes turned off- must enable run time type info setting

-----------------------------------------------------------------------------
Feature                 Increases         Increases        Reduces
                      Size of Objects   Per-class data     Inlining
-----------------------------------------------------------------------------
Virtual Functions           Yes               Yes             Yes 
Multiple Inheritance        Yes               Yes             No 
Virtual Base Classes       Often           Sometimes          No 
RTTI                        No                Yes             No 


//////////////////////////////////////////////////////////////////////////////
//OPERATOR OVERLOADING
//////////////////////////////////////////////////////////////////////////////

OPERATOR OVERLOADING RESTRICTIONS
 • Must have one argument as an object
 • You can't violate the syntax rules for the original operator 
   (ie. /2 or %2 cannot be done but +2 is okay)
 • Can't change precedence
 • Can't create new symbols

CAN'T BE OVERLOADED
.         The membership operator
.*        The pointer-to-member operator
::        The scope-resolution operator
?:        The conditional operator
sizeof    The sizeof operator

ONLY OVERLOADED BY METHODS
=         Assignment operator
()        Function call operator
[]        Subscripting operator
->        Class member access by pointer operator

CAN BE OVERLOADED
+       -       *       /       %       ^
&       |       ~=      !       =       <
>       +=      -=      *=      /=      %=
^=      &=      |=      <<      >>      >>=
<<=     ==      !=      <=      >=      &&
||      ++      --      ,       ->*     ->
()      []      new     delete  new[]   delete[]

//////////////////////////////////////////////////////////////////////////////
//OVERLOAD RESOLUTION
//////////////////////////////////////////////////////////////////////////////

Function signature can differ by:
  1) Type of parameters
  2) Number of parameters
  3) Const or not const parameters (for pointer/byref passing only)

For a given function name, you can have in order of overloading:
  • non-template function 
  • explicit specialization template function
  • a template function (implicit/explicit instantiation)

----------------------------------------------------------------------------
[1] DETERMINING WHICH FUNCTION TO USE
----------------------------------------------------------------------------

1) Assemble list of candidate functions with the same name as called function

2) From the candidate functions, assemble a list of viable functions: 
    - functions with same number/type of parameters as arguments sent
    - functions that can do automatic type conversion on arguments also listed

3) Determine whether there is a best viable function, otherwise error

----------------------------------------------------------------------------
[2] CHOOSING OUT OF POSSIBLE REMAINING THE HIGHEST PRIORITY FUNCTION
----------------------------------------------------------------------------

1. Exact match, with regular functions outranking templates.
2. Argument conversion by Automatic type conversion 
   (promotion/standard conversion)
3. User-defined conversions, such as those defined in class declarations

----------------------------------------------------------------------------
[3] RESOLVING IF MULTIPLE CAN BE CHOSEN
----------------------------------------------------------------------------

//OKAY
void recycle(int * x); <-- matches with non-const pointers
void recycle(const int * x); <-- matches with const pointers

void recycle(int & i); <-- matches with non-const data
void recycle(const int & i); <-- matches with const data

//ERROR
void recycle(int i);
void recycle(const int i);

//////////////////////////////////////////////////////////////////////////////
//TEMPLATES
//////////////////////////////////////////////////////////////////////////////

IMPLICIT INSTANTIATION
Use the arguments provided and decide what function declaration to create from the template

EXPLICIT INSTANTIATION
Use template to generate a function definition for an individual type specified in code

EXPLICIT SPECIALISATION
Don't use the template to create function; use a seperate specialised function specified in code

*//////////////////////////////////////////////////////////////////////////////