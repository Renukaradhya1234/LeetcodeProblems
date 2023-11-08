Declare
  string varchar(20);
  var_result varchar(20);
  i number := 1;
Begin
  string := & string;
  while i < length(string) 
    loop
      if substr(string, i, 1) in ('a', 'e', 'i', 'o', 'u') then
        var_result := var_result || substr(string, i, 1);
      end if;
    end loop;
  dbms_output.put_line(var_result);
end;
/
