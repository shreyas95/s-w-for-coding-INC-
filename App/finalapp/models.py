from django.db import models
from djangotoolbox.fields import EmbeddedModelField,ListField
# Create your models here.


class Users(models.Model):
	Player1Name = models.CharField(max_length = 50)
	Player2Name = models.CharField(max_length = 50)
	TeamName = models.CharField(max_length = 50)                        
	Password = models.CharField(max_length = 20)
	Email = models.CharField(max_length = 50)
	ReceiptNumber = models.CharField(max_length = 50)                    #unique id
	TotalSubmission = models.IntegerField()
	Score_list = ListField(models.IntegerField())
	Final_score = models.IntegerField()
	
	start_time=models.DateTimeField(auto_now=False,auto_now_add=False,null=True,blank=True)
	end_time=models.DateTimeField(auto_now=False,auto_now_add=False,null=True,blank=True)
	first_login=models.BooleanField(default=True)
	Submission_time_list = ListField(models.IntegerField())
	Total_time = models.IntegerField()

