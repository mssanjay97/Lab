/*EXECUTED ON: w3schools.com https://www.w3schools.com/sql/trysql.asp?filename=trysql_op_in 
NOTE:RUN ALL COMMANDS INDIVIDUALLY.
*/
create table job (Instructor varchar(30) NOT NULL, Subject varchar(30) NOT NULL,primary key(Instructor,Subject) );

insert into job values('Aleph','Scratch'),('Aleph','Java'),('Aleph','Processing'),('Bit','Python'),('Bit','Javascript'),('Bit','Java'),('CRC','Python'),('CRC','Javascript'),('Dat','Scratch'),('Dat','Python'),('Dat','Javascript'),('Emscr','Scratch'),('Emscr','Processing'),('Emscr','Javascript'),('Emscr','Python');
/*
SOLUTION 1: Using intersect 
*/
select Instructor from job where Subject ='Javascript' intersect select Instructor from job where Subject ='Scratch' intersect select Instructor from job where Subject ='Python' ;
/*
Result:
Number of Records: 2
Instructor
Dat
Emscr

EXPLANATION: 
We need to find instructor who teaches all three courses. One approach is we first find the list of all instructors who teach each of the 3 courses(i. find all instructors who can teach Javascript, find all instructors who can teach Python and find all instrutors who can teach Scratch) and then from those instructors list, find the instructors who teach all.i.e. find instructors who are present in every list.It is equivalent to do set intersection of all the lists.    


the query " select Instructor from job where Subject ='Javascript' " selects all instructors who teach Javascript. 

the query " select Instructor from job where Subject ='Scratch' " selects all instructors who teach Scratch. 
 

Intersect keyword finds all instructor values that are common to both tables. i.e. finds instructors who teach both Javascript and Scratch


the query " select Instructor from job where Subject ='Python' " selects all instructors who teach Python.

Second intersect keyword finds all instructor who teach Python and who teach both Javascript and Scratch(result of previous query) ie. essentiall teach all 3 subjects

*/


