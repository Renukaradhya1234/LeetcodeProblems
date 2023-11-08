create or replace function fun_check_bonus( salary in number, hike in number)
return varchar
is
Begin
	if salary > hike then
		return 'eligible';
	else
		return 'not eligible';
	end if;
End;
/
