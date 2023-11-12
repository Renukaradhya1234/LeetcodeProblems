from django.urls import path
from . import views
urlpatterns = [
    path("login/", views.renderLoginPage, name="login"), # navigating to home page
    path("registration/", views.renderRegistrationPage, name="registration"), # navigating to registration page
    path("enquiry/<id>", views.renderEnquiryPage, name="enquiry") # navigating to enquiry page
]