create or replace function even_odd_function( num in number)
return varchar
as
Begin
	if mod(num, 2) = 0 then
		return 'even number';
	else
		return 'odd number';
	end if;
End;
/
