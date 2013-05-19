//////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
//////////////////////////////////////////////////////////////////////////////
/*

FUNCTION DECLARATION/PROTOTYPE: Function header
FUNCTION DEFINITION: Function including body

FUNCTION CALLING
1) program places address of calling function on stack
2) any variables used locally are created as auto vars and placed on stack
3) if function calls another its information is placed on top of stack

RETURNING VALUES
1) Returns a value by copying the return value to a specified register/location
2) The calling function examines that location. Both the returning and 
   calling function have to agree on the type of data at that location. 

ARGUMENTS/PARAMETERS
Actual Argument/Parameter = The value passed to the function 
Formal Argument/Parameter = A variable that’s used to receive passed values
Argument = used to denote Actual Argument/Parameter
Parameter = used to denote Formal Argument/Parameter 

ORDER OF ARGUMENT EVALUATION
Order that function parameters are evaluated is up to the complier.
callFunc(getA(),getB()); can either be:

    int a = getA();       int b = getB();
    int b = getB();  OR   int a = getA();
    callFunc(a,b);        callFunc(a,b);


//////////////////////////////////////////////////////////////////////////////
//OBJECT ORIENTED PROGRAMMING
//////////////////////////////////////////////////////////////////////////////

6 MOST IMPORTANT OOP FEATURES
    P • Polymorphism
    A • Abstraction
    I • Inheritance
    R • Reusability of code
    E • Encapsulation 
    D • Data hiding

POLYMORPHISM: 
• When a function can operate with values of at least two distinct types 
  and executes type-appropriate code

ABSTRACTION: 
• Sectioning off variables/functions into private (IMPLEMENTATION) and 
  public (INTERFACE) of a class
 
INHERITANCE:
• Using previously written classes as a base for new classes.

RE-USABILITY:
• Using inheritance/functions/templates to prevent code duplication.

DATA HIDING: 
• The insulation of data from direct access by a program

ENCAPSULATION: 
• The wrapping of data and functions with common features into a single class/structure

//////////////////////////////////////////////////////////////////////////////
//CLASSES AND OBJECTS
//////////////////////////////////////////////////////////////////////////////

STRUCTURE/CLASS DIFFERENCES: 
• Class members/inheritance is private by default
• Struct members/inheritance is public by default

AGGREGATE:
• Array/class/struct/union with no user-declared constructors, private and 
  protected non-static data members, base classes and virtual functions.
• Array is an aggregate even it is an array of non-aggregate class type.
• Doesn't matter what static members it has
• Can be initialized with {}

PLAIN-OLD-DATA (POD):
• An aggregate class with no user-declared assignment op/destructor,
  Non-static members have to be POD types, non-static arrays have to hold 
  POD types and references have to refer to POD types;
• Doesn't matter what static members it has

==========================================================================
CLASS CONSTRUCTION
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
FRIEND FUNCTION
==========================================================================
• Not invoked by object, Doesn't use CLASS::, use as a normal function
• A friend of a class can see that class's private bits
• No 'this' pointer

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

==========================================================================
FUNCTORS
==========================================================================
Class/struct with operator() that allows objects to act as functions

Types of Functors:
  • GENERATOR: called with no arguments.
  • UNARY FUNCTION: called with one argument.
  • BINARY FUNCTION: called with two arguments.
  • PREDICATE: unary function that returns a bool
  • BINARY PREDICATE: binary function that returns a bool

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

==========================================================================
INHERITANCE RELATIONSHIPS
==========================================================================

IS-A RELATIONSHIP
Class inherits an interface + implementation for non pure virtual functions
Eg. Public inheritance

HAS-A RELATIONSHIP
Class acquires implementation without the interface 
(interface can still be used within class methods, but not outside class)
Eg. Containment/Composition/Layering, Private/Protected inheritance

//////////////////////////////////////////////////////////////////////////////
//VIRTUAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

STATIC BINDING: 
Which function called is known at compilation
Uses the pointer type (non-virtual, default values)

DYNAMIC BINDING: 
Not always known whether base/derived method is needed
Uses the object type no matter the pointer type (virtual functions)

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
•  Virtual Base Classes only have one copy of the base class object no 
   matter how many derived objects inherited into the third object 
   derived from the base. Plain multiple inheritance has one for every 
   derived from the base.
•  Derived objects must call base class constructor explicitly when 
   third+ generation

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
//POLYMORPHISM
//////////////////////////////////////////////////////////////////////////////

To exhibit polymorphism, f() must be able to operate with values of at least 
two distinct types finding and executing type-appropriate code.

1) PREPROCESSING (AD-HOC/PARAMETRIC)
    #define f(int x) ((x) += 2)
    #define f(double x) ((x) += 2)
    #define f(X) ((X) += 2)

2) OVERLOADING (AD-HOC)
    void f(int& x)    { x += 2; }
    void f(double& x) { x += 2; }

3) TEMPLATES (PARAMETRIC)
    template <typename T>
    void f(T& x) { x += 2; }

4) VIRTUAL METHODS (AD-HOC)
    BaseClass* pBase = &derivedObject;
    pBase->MyVirtualFunction();

AD-HOC POLYMORPHISM: object types are explicitly defined for overloading
PARAMETRIC POLYMORPHISM: object types aren't defined, any object can be used

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
.                    The membership operator
.*                   The pointer-to-member operator
::                   The scope-resolution operator
?:                   The conditional operator
sizeof               The sizeof operator

ONLY OVERLOADED BY METHODS
=                   Assignment operator
()                  Function call operator
[]                  Subscripting operator
->                  Class member access by pointer operator

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