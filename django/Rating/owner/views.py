from django.shortcuts import render, redirect
from django.urls import reverse
from .forms import *
# Create your views here.
def renderLoginPage(request):
    if request.method == "GET":
        return render(request, "login.html")
    elif request.method == "POST":
        username = request.POST["username"]
        password = request.POST["password"]

        user = RegistrationTable.objects.get(username = username)

        if (user.authenticate(username, password)):
            return redirect(reverse("enquiry", kwargs={"id" : user.customerId}))
        else:
            return render(request, "login.html", {"loginstatus" : "login unsuccesfull"})

def renderRegistrationPage(request):
    if request.method == "GET":
        regForm = RegistrationForm()
        return render(request, "registration.html", {"regForm" : regForm})
    elif request.method == "POST":
        regForm = RegistrationForm(request.POST)
        if (regForm.is_valid()):
            regForm.save()
            return redirect("/owner/login/")
        else:
            return render(request, "registration.html", {"regForm" : regForm})
        
def renderEnquiryPage(request, id):
    if request.method == "GET":
        enqForm = EnquiryForm(initial={"customerId" : id})
        return render(request, "enquiry.html", {"enqForm" : enqForm})
    elif request.method == "POST":
        enqForm =  EnquiryForm(request.POST)
        if (enqForm.is_valid()):
            enqForm.save()
            return render(request, "enquiry.html", {"enqForm" : enqForm, 
                                                    "storeStatus" : "data stored successfully..."})
        else :
            return render(request, "enquiry.html", {"enqForm" : enqForm, 
                                                    "storedStatus": "data not stored"})
