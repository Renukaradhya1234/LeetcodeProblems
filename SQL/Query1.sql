SELECT e.*
FROM employees e
    inner join departments d
      on e.department_id = d.department_id
WHERE d.department_name = 'SALES';
