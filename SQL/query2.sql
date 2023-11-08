SELECT e.first_name, e.last_name
FROM employees e
      inner join departments d
          on e.department_id = d.department_id
      inner join locations l
          on d.location_id = l.location_id
      inner join country c
          on l.country_id = c.country_id
WHERE c.country_name = 'AUSTRAILA';
