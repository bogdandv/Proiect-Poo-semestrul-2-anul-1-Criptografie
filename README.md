# Proiect-Poo-semestrul-2-anul-1-Criptografie

	
This project has a basic structure:
there are a few important classes (the interface class). These are Composition_law_interface,Additive_Group_interface,Multiplcative_Group_interface,Field_interface,element_interface 
There is a class called element which will be used to make calculations using diverse fields. 
If a correct value and a correct field (aka derived from Field_interface) is given then the item will be able to make basic calculations, no matter what field or value is given. Thus with an instance of item you can use a rational field, a complex field or a finite one and make calculations using specific rules. Every class written in this project (except the user interface) will be derived from one of the interface class, thus assuring that if 1 programmer implements a finite composition law using Caylays table and the other using some sort of mathematical calculations, then both classes can be used with the Finite_Additive_Group or Finite_Multiplicative_group. Same goes if you implement a new Group that finds out quicker if the Group is associative. One item has a field and a value. One field has an aditive group and a multiplicative group. Each group has a composition law. All of them inherit the proper interface. 
 
The rules of calculation (for example 1+2i + 2-1i = 3+i) are implemented in the Return_composite function in the composition law The conditions for asociativity, commutativity etc. are dependent on the field being implemented, thus must be written separately by the programmer. Each class has a template that will determine the datatype of "value" from item (for example on complex fields it will be a pair, in real fields it will be a double)
 

