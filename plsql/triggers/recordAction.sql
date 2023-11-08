create table action_record(
  ename varchar(20);
  action_column varchar(20);
);

create or replace trigger tri_action
before
update or insert or delete 
on emp
for each row

Declare
  action_var varchar(20);
Begin
  if inserting then
    action_var := 'INSERTING';
  elsif deleting then
    action_var := 'DELETING';
  else 
    action_var := 'UPDATING';
  end if;

  insert into action_record values( :old.ename, :old.action_var);
  dbms_output.put_line('employee :' || :old.ename || ' added to the table with action '|| action_var);
End;
/
