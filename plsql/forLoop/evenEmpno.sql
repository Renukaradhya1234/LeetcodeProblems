declare 
	emp_id number;
	cursor emp_empno is 
		select empno
		from emp;
begin
	for emp_id in emp_empno
		loop
			if mod(emp_id.empno, 2) = 0 then
				dbms_output.put_line(emp_id.empno);
			end if;
		end loop;
end;
/
