from django.shortcuts import render, redirect
from django.http import HttpResponse
from .forms import *
from django.contrib.auth.hashers import make_password
import qrcode
from django.urls import reverse

# Create your views here.
def dashboard_trainer(request):
    if request.method == 'POST': 
        key = request.POST.get('key')
        obj = TrainerDetails.objects.filter(tname = key)
        return render(request, 'trainer_details.html', {'data': obj})
    else:
        obj = TrainerDetails.objects.all()
        return render(request, 'trainer_details.html', {'data': obj})

def dashboard_employee(request):
    if request.method == 'POST':
        key = request.POST.get('key')
        obj = EmployeeDetails.objects.filter(ename = key)
        return render(request, 'employee_details.html', {'data': obj})
    else:
        obj = EmployeeDetails.objects.all()
        return render(request, 'employee_details.html', {'data': obj})

def dashboard_member(request):
    if request.method == 'POST':
        key = request.POST.get('key')
        obj = MemberDetails.objects.filter(mname = key)
        return render(request, 'member_details.html', {'data': obj})
    else:
        obj = MemberDetails.objects.all()
        return render(request,'member_details.html', {'data': obj})

def dashboard_trainer_add(request):
    if request.method == 'POST':
        form = TrainerForm(request.POST, request.FILES)
        if form.is_valid():
            ref = form.save(commit = False)
            old_password = ref.tpassword
            print(f'this is old trainer password: {old_password}')
            ref.tpassword = make_password(ref.tpassword)
            new_password= ref.tpassword
            print(f'this is new trainer password: {new_password}')
            ref.save()
            return redirect('/owner/trainer/')
        else:
            print(form.errors)
            return render(request, 'forms.html', {'form': form, 
                                                  'heading': 'Trainer Registration',
                                                  'button_name': 'Add',
                                                  'back_page': 'trainer',
                                                  'title': 'Trainer Add'})
    else:
        form = TrainerForm()
        return render(request, 'forms.html', {'form': form, 
                                              'heading': 'Trainer Registration',
                                              'button_name': 'Add',
                                              'back_page': 'trainer',
                                              'title': 'Trainer Add'})
    
def dashboard_employee_add(request):
    if request.method == 'POST':
        form = EmployeeForm(request.POST, request.FILES)
        if form.is_valid():
            ref = form.save(commit=False)
            old_password = ref.epassword
            print(f'this is old employee password: {old_password}')
            ref.epassword = make_password(ref.epassword)
            new_password = ref.epassword
            print(f'this is new employee password: {new_password}')
            ref.save()
            return redirect('/owner/employee/')
        else:
            return render(request, 'forms.html', {'form': form,
                                                  'heading': 'Employee Registration',
                                                  'button_name': 'Add',
                                                  'back_page': 'employee',
                                                  'title': 'Employee Add'})
    else:
        form = EmployeeForm()
        return render(request, 'forms.html', {'form': form, 
                                              'heading': 'Employee Registration',
                                              'button_name': 'Add',
                                              'back_page': 'employee',
                                              'title': 'Employee Add'})
    
def dashboard_member_add(request):
    if request.method == 'POST':
        form = MemberForm(request.POST, request.FILES)
        if form.is_valid():
            ref = form.save(commit=False)
            old_password = ref.mpassword
            print(f'this is old member password: {old_password}')
            ref.mpassword = make_password(ref.mpassword)
            new_password = ref.mpassword
            print(f'this is new member password: {new_password}')
            ref.save()
            return redirect('/owner/member/')
        else:
            return render(request, 'forms.html', {'form': form, 
                                                  'heading': 'Member Registration',
                                                  'button_name': 'Add',
                                                  'back_page': 'member',
                                                  'title': 'Member Add'})
    else:
        form = MemberForm()
        return render(request, 'forms.html', {'form': form, 
                                              'heading': 'Member Registration',
                                              'button_name': 'Add',
                                              'back_page': 'member',
                                              'title': 'Member Add'})
    
def dashboard_trainer_update(request, id):
    obj = TrainerDetails.objects.get(tid = id)
    if request.method == 'POST':
        form = TrainerUpdateForm(request.POST, request.FILES, instance=obj)
        if form.is_valid():
            form.save()
            return redirect('/owner/trainer/')
        else:
            return render(request, 'forms.html', {'form': form,
                                                  'heading': 'Trainer Updation Form',
                                                  'button_name': 'Update',
                                                  'back_page': 'trainer',
                                                  'title': 'Trainer Update'})
    else:
        form = TrainerUpdateForm(instance = obj)
        return render(request,'forms.html', {'form': form,
                                             'heading': 'Trainer Updation Form',
                                             'button_name': 'Update',
                                             'back_page': 'trainer',
                                             'title': 'Trainer Update'})

def dashboard_employee_update(request, id):
    obj = EmployeeDetails.objects.get(eid = id)
    if request.method == 'POST':
        form = EmployeeUpdateForm(request.POST, request.FILES, instance=obj)
        if form.is_valid():
            form.save()
            return redirect('/owner/employee/')
        else:
            return render(request, 'forms.html', {'form': form,
                                                  'heading': 'Employee Updation Form',
                                                  'button_name': 'Update',
                                                  'back_page': 'employee',
                                                  'title': 'Employee Update'})
    else:
        form = EmployeeUpdateForm(instance = obj) 
        return render(request, 'forms.html', {'form': form,
                                              'heading': 'Employee Updation Form',
                                              'button_name': 'Update',
                                              'back_page': 'employee',
                                              'title': 'Employee Update'})

def dashboard_member_update(request, id):
    obj = MemberDetails.objects.get(mid = id)
    if request.method == 'POST':
        form = MemberUpdateForm(request.POST, request.FILES, instance = obj)
        if form.is_valid():
            form.save()
            return redirect('/owner/member/')
        else:
            return render(request, 'forms.html', {'form': form,
                                                  'heading': 'Member Updation Form',
                                                  'button_name': 'Update',
                                                  'back_page': 'member',
                                                  'title': 'Member Update'})
    else:
        form = MemberUpdateForm(instance = obj)
        return render(request, 'forms.html', {'form': form,
                                              'heading': 'Member Updation Form',
                                              'button_name': 'Update',
                                              'back_page': 'member',
                                              'title': 'Member Update'})
    
def dashboard_employee_delete(request, id):
    try:
        obj = EmployeeDetails.objects.get(eid = id).delete()
        return redirect('/owner/employee/')
    except Exception as e:
        return HttpResponse(f'Some Error: {e}')

def dashboard_trainer_delete(request, id):
    try:
        obj = TrainerDetails.objects.get(tid = id).delete()
        return redirect('/owner/trainer/')
    except Exception as e:
        return HttpResponse(f'Some Error: {e}')

def dashboard_member_delete(request, id):
    try:
        obj = MemberDetails.objects.get( mid = id).delete()
        return redirect('/owner/member/')
    except Exception as e:
        return HttpResponse(f'Some error: {e}')
    
# to navigate dynamic route
def generate_dynamic_route(view_name, **kwargs):
    print(f'this is from generatore dynamic route funtion:{kwargs}')
    return reverse(view_name, kwargs=kwargs)
    
def dashboard_employee_details(request, id):
    try:
        obj = EmployeeDetails.objects.get(eid = id)
        context = {
            'title': 'Employee Details',
            'refid': obj.eid,
            'name': obj.ename,
            'dob': obj.edob,
            'gender': obj.egender,
            'email': obj.eemail,
            'phone': obj.ephone,
            'image': obj.eimage.url,
            'back_page': generate_dynamic_route('employee'),
            'update_name': generate_dynamic_route('updateemployee', id=obj.eid),
            'delete_name': generate_dynamic_route('deleteemployee', id=obj.eid),
            'qrcode':generate_dynamic_route('qrcodeGenerator', id=obj.eid, database = 'employee')
        }
        return render(request, 'details.html', context)
    except Exception as e:
        return render(request, 'details.html', {'error': f'Something error: {e}'})
    
def dashboard_trainer_details(request, id):
    try:
        obj = TrainerDetails.objects.get(tid = id)
        print(obj.tid)
        context = {
            'title': 'Trainer Details',
            'refid': obj.tid,
            'name': obj.tname,
            'dob': obj.tdob,
            'gender': obj.tgender,
            'email': obj.temail,
            'phone': obj.tphone,
            'image': obj.timage.url,
            'back_page': generate_dynamic_route('trainer'),
            'update_name': generate_dynamic_route('updatetrainer', id=obj.tid),
            'delete_name': generate_dynamic_route('deletetrainer', id=obj.tid),
            'qrcode': generate_dynamic_route('qrcodeGenerator', id=obj.tid, database='trainer')
        }
        print()
        return render(request, 'details.html', context)
    except Exception as e:
        return render(request, 'details.html', {'error': f'Something error: {e}'})
    
def dashboard_member_details(request, id):
    try:
        obj = MemberDetails.objects.get(mid = id)
        context = {
            'title': 'Member Details',
            'refid': obj.mid,
            'name': obj.mname,
            'dob': obj.mdob,
            'gender': obj.mgender,
            'email': obj.memail,
            'phone': obj.mphone,
            'trainerid': obj.mtrainerid,
            'image': obj.mimage.url,
            'back_page': generate_dynamic_route('member'),
            'update_name': generate_dynamic_route('updatemember', id=obj.mid),
            'delete_name': generate_dynamic_route('deletemember', id=obj.mid),
            'qrcode': generate_dynamic_route('qrcodeGenerator', id=obj.mid, database='member')
        }
        print('this is print')
        print(context['update_name'])
        return render(request, 'details.html', context)
    except Exception as e:
        print(f' Something error: {e}')
        return render(request, 'details.html', {'error': f'Something Error: {e}'})
    
def qrcode_generator(request, id, database):
    print(f'called qrcode_generator function')
    if database == 'trainer':
        print(f'generatoring trainer details qrcode ')
        obj = TrainerDetails.objects.get(tid = id)
        data = {
            'Name': obj.tname,
            'Date of Birth': obj.tdob,
            'Gender': obj.tgender,
            'Email': obj.temail,
            'Phone': obj.tphone,
        }
        qr = qrcode.QRCode(
            box_size=10,
            border=4,
        )

        qr.add_data(data)

        qr_img = qr.make_image(fill_color="black", back_color="white")
        response = HttpResponse(content_type='image/png')
        qr_img.save(response, 'PNG')
        return response
    elif database == 'member':
        obj = MemberDetails.objects.get(mid = id)
        data = {
            'Name': obj.mname,
            'Date of Birth': obj.mdob,
            'Gender': obj.mgender,
            'Email': obj.memail,
            'Phone': obj.mphone,
        }
        qr = qrcode.QRCode(
            box_size=10,
            border=4,
        )

        qr.add_data(data)

        qr_img = qr.make_image(fill_color="black", back_color="white")
        response = HttpResponse(content_type='image/png')
        qr_img.save(response, 'PNG')
        return response

    else:
        obj = EmployeeDetails.objects.get(eid = id)
        data = {
            'Name': obj.ename,
            'Date of Birth': obj.edob,
            'Gender': obj.egender,
            'Email': obj.eemail,
            'Phone': obj.ephone,
        }
        qr = qrcode.QRCode(
            box_size=10,
            border=4,
        )

        qr.add_data(data)

        qr_img = qr.make_image(fill_color="black", back_color="white")
        response = HttpResponse(content_type='image/png')
        qr_img.save(response, 'PNG')
        return response

    





