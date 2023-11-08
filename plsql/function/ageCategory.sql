create or replace function fun_age( age in number)
return varchar
is
Begin
	if age between 0 and 15 then
		return 'younge';
	elsif age between 16 and 25 then
		return 'Adult';
	else
		return 'Elder';
	end if;
End;
/
