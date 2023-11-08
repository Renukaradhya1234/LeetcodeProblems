Declare
  name varchar(20);
  salary number;
Begin
  select ename, sal into
         name, salary
  from emp
  where empno = 7893;

  dbms_output.put_line(name || ' earns ' || salary);
Exception
  when NO_DATA_FOUND then
    dbms_output.put_line('No record...');
  when TOO_MANY_ROWS then
    dbms_output.put_line('More than 1 records found...');
  when OTHERS then
    dbms_output.put_line('Some error found...');
End;
/
