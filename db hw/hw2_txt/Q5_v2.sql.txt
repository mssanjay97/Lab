/*
EXECUTED ON: w3schools.com https://www.w3schools.com/sql/trysql.asp?filename=trysql_op_in
NOTE:RUN ALL COMMANDS INDIVIDUALLY.
*/
/*
SOLUTION 2: using natural join
*/
select * from (select Instructor from job j1 where Subject ='Javascript') natural join (select Instructor from job j2 where Subject ='Scratch') natural join (select Instructor from job j3 where Subject ='Python') ;
/*
Number of Records: 2
Instructor
Dat
Emscr

EXPLANATION:
We can create 3 separate tables where we have instructors who teach one particular subject i.e. one table which has instructor who teaches Javascript, second table which has instrutors who teach Scratch and third table which has instructors who teach Python.
Then we can join the tables based on the Instructor field so that we get a new table which contains instrutors who teach all 3 subjects. 

(select Instructor from job j1 where Subject ='Javascript') creates a table which has Instrucotrs who teach Javascript 

(select Instructor from job j1 where Subject ='Scratch') creates a table which has Instrucotrs who teach Scratch

the 1st natural join keyword joins both the tables based on common values of the Instructor field i.e. it creates a new table which has instructor who teach both Javascript and Scratch because only if a particular instructor is present in both the table,only then the join can use the instructor value to join the table.

(select Instructor from job j1 where Subject ='Python') creates a table which has Instrucotrs who teach Python

the 2nd natural join keyword joins the two tables based on common values of the Instructor field i.e. it creates a new table which has instructor who teach both Javascript,Scratch  and Python because only if a particular instructor is present in both the table,only then the join can use the instructor value to join the table.
So at the end of the operation we have a table which is joined on all 3 courses.SO this final table has the list of all instructors who teach all the 3 courses.

*/