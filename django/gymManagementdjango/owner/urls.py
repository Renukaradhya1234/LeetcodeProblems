from django.urls import path
from . import views
urlpatterns = [
    path('trainer/', views.dashboard_trainer, name='trainer'),
    path('member/', views.dashboard_member, name='member'),
    path('employee/', views.dashboard_employee, name='employee'),

    path('trainerAdd/', views.dashboard_trainer_add, name='addtrainer'),
    path('employeeAdd/', views.dashboard_employee_add, name='addemployee'),
    path('memberAdd/', views.dashboard_member_add, name='addmember'),

    path('trainerUpdate/<int:id>', views.dashboard_trainer_update, name='updatetrainer'),
    path('employeeUpdate/<int:id>', views.dashboard_employee_update, name='updateemployee'),
    path('memberUpdate/<int:id>', views.dashboard_member_update, name='updatemember'),

    path('trainerDelete/<int:id>', views.dashboard_trainer_delete, name='deletetrainer'),
    path('employeeDelete/<int:id>', views.dashboard_employee_delete, name= 'deleteemployee'),
    path('memberDelete/<int:id>', views.dashboard_member_delete, name='deletemember'),

    path('trainerDetails/<int:id>', views.dashboard_trainer_details, name='detailstrainer'),
    path('employeeDetails/<int:id>', views.dashboard_employee_details, name='detailsemployee'),
    path('memberDetails/<int:id>', views.dashboard_member_details, name='detailsmember'),

    path('qrcode/<int:id>/<database>', views.qrcode_generator, name='qrcodeGenerator'),

    
]