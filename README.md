#Data Structures
A data structure library for C
##Generic Without Generation
The structures use void pointers, memory copying, and size storage to perform generic operations without having to generate a copy of the struct for every type it is used for

##Disadvantages
The type of the data held in the structure cannot be stored, so the only way to know what type has been passed is documentation and trust. This does remove a large layer of safety from the language, but can be mitigated with care.
