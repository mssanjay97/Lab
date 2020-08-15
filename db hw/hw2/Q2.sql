/*EXECUTED ON: w3schools.com  https://www.w3schools.com/sql/trysql.asp?filename=trysql_op_in
NOTE:RUN ALL COMMANDS INDIVIDUALLY.
 */

create table class (SID number not null,className varchar(20) not null, grade char(2),primary key(SID,className,grade) );

insert into class values (123,'Processing','A'),(123,'Python','B'),(123,'Scratch','B'),(662,'Java','B'),(662,'Python','A'),(662,'Javascript','A'),(662,'Scratch','B'),(345,'Scratch','A'),(345,'Javascript','B'),(345,'Python','A'),(555,'Python','B'),(555,'Javascript','B');

select className as ClassName, count(*) as Total from class group by className order by 2 desc;       

/*
Result:
Number of Records: 5
ClassName	Total
Python	4
Scratch	3
Javascript	3
Processing	1
Java	1
 
*/

