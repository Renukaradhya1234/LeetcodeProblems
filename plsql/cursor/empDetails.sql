declare
	cursor emp_details is
		select ename, sal, dname
		from emp e
			inner join dept d
				on e.deptno = d.deptno;
Begin
	for single in emp_details
		loop
			dbms_output.put_line('Employee Name: '||single.ename|| ' Employee Salary: '||single.sal||' Dept Name: '||single.dname);
		end loop;
End;
/
