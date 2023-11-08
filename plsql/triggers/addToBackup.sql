create or replace trigger tri_backup
before
delete
on emp
for each row

Begin
  insert into backup values( :old.empno, :old.ename, :old.job, :old.mgr, :old.hiredate, :old.sal, :old.comm, :old.deptno);
  dbms_output.put_line(' employee ' || :old.ename || 'added to backup table');
End;
/
