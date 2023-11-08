create or replace function fun_salary_increase( salary in number, percentage in number)
return number
as
	new_salary number;
Begin
	new_salary := salary + (salary * (percentage/100));
	return new_salary;
End;
/
