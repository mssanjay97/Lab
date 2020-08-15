/*
EXECUTED ON: w3schools.com https://www.w3schools.com/sql/trysql.asp?filename=trysql_op_in 
NOTE:RUN ALL COMMANDS INDIVIDUALLY.
*/
create table spam (Name varchar(30) not null,Address varchar(50) not null,ID number primary key,SameFam number);

insert into spam values ('Alice','A',10,null),('Bob','B',15,null),('Carmen','C',22,null),('Diego','A',9,10),('Ella','B',3,15),('Farkhad','D',11,null);

delete from spam where ID in (select distinct(SameFam)from spam) and SameFam is null;
/*
Result:
You have made changes to the database. Rows affected: 2
*/

update spam set SameFam=null;
/*
Since there are atmost 2 members and we are deleting 1 member, it is obvious that only 1 member of a family remains and it can be seen that the SameFam should be NULL because no other family member is present. So we can set all rows to have NULL SameFam as no other family member of any person is present.

Result:
You have made changes to the database. Rows affected: 4
*/
select * from spam;
/*
Result:
Number of Records: 4
Name	Address	ID	SameFam
Carmen	C	22	null
Diego	A	9	null
Ella	B	3	null
Farkhad	D	11	null


ASSUMPTION: DISTINCT(SameFam) might contain null but since ID is primary key, it wont be null. So there is no possibility of a null ID matching to a null SameFam. Also the and condition SameFam is null is redundant if we assume that only maximum 2 members of a family can be in table. In such a case, one of the members must have a NULL SameFam value and whose ID is also in SameFam of another row. So it is like doing duplicate checking. 

*/


/*ALTERNATE SIMPLER SOLUTION executed on :https://livesql.oracle.com/
Use on delete set null command when creating foreign key
*/

create table spam (Name varchar(30) not null,Address varchar(50) not null,ID number primary key,SameFam number,foreign key(SameFam) references spam(ID) on 

delete set null);
insert into spam values ('Alice','A',10,null);
insert into spam values ('Bob','B',15,null);
insert into spam values ('Carmen','C',22,null);
insert into spam values ('Diego','A',9,10);
insert into spam values ('Ella','B',3,15);
insert into spam values ('Farkhad','D',11,null);
delete from spam where ID 

in (select distinct(SameFam)from spam) and SameFam is null;
select * from spam;

/*OUTPUT:

Table created.

1 row(s) inserted.

1 row(s) inserted.

1 row(s) inserted.

1 row(s) inserted.

1 row(s) inserted.

1 row(s) inserted.

2 row(s) deleted.

Result Set 3
NAME	ADDRESS	ID	SAMEFAM
Carmen	C	22	 - 
Diego	A	9	 - 
Ella	B	3	 - 
Farkhad	D	11	 - 

*/
