from django.http import *
from django.shortcuts import render
from finalapp.models import *
from django.views.decorators.csrf import csrf_exempt
from django.template import Template, Context
import datetime
import json
from django.core import serializers
from django.utils import timezone
from django.http import Http404
# Create your views here.

import sys
import os
import subprocess



@csrf_exempt
def remove_extra(s):
	if len(s) == 0: 
		return s
	i = -1
	while s[i] == "\n":
		i -= 1
	if i < -1:
		s = s[:i+1]
	print s
	return s

@csrf_exempt
def file_read(filename,file1):
	if os.path.exists(filename): 
		f = open(filename,"r"); d = f.read(); f.close();
	if os.path.exists(file1): 
		f = open(file1,"r"); e = f.read(); f.close();
	s1=remove_extra(d)
	s2=remove_extra(e)
	if s2==s1:
		return 1
	else :
		return 0


def timer_help(request,user_id):
	print "timer_help"
	print user_id
	if request.is_ajax():
		obj = Users.objects.filter(ReceiptNumber=user_id)
		print "in if"
		time=obj[0].end_time
		print time
		nw=datetime.datetime.now()		
		print nw
		delta= time - nw
		print delta
		seconds=delta.total_seconds()
		data = {}
		data['time_left'] = seconds
		print seconds
		return HttpResponse(json.dumps(data), content_type = "application/json")
	raise Http404("Not found")


@csrf_exempt	
def render_login_page(request):
	print "render_login_page"
	if request.method == 'POST':
		print request.POST.keys()
		
		player1name = request.POST['player1_name']
		player2name = request.POST['player2_name']
		teamname = request.POST['team_name']
		password = request.POST['password']
		email = request.POST['email']
		receiptnumber = request.POST['receipt_number']
		score_list = [0,0,0,0,0,0,0,0]
		
		obj = Users.objects.filter(ReceiptNumber = receiptnumber)
		if len(obj)==0:
			s = e = datetime.datetime.now()
			obj = Users(Player1Name=player1name,Player2Name=player2name,TeamName=teamname,Password=password,Email=email,ReceiptNumber=receiptnumber,TotalSubmission = 0,Score_list=score_list,Final_score=0,start_time=s,end_time = e,Total_time=0,Submission_time_list=score_list)
			obj.save()
			
			
		
		return HttpResponseRedirect('/user/'+receiptnumber)
	else:
		return render(request,'pradnya_1.html')
		
@csrf_exempt	
def render_instruction_page(request,user_id):
	if request.method == 'POST':
		print "POST in render_instruction_page"
		obj1 = Users.objects.filter(ReceiptNumber=user_id)
		if obj1[0].first_login == True:
			s=timezone.make_aware(datetime.datetime.now(),timezone.get_current_timezone())
			e = s+datetime.timedelta(hours=3)
			obj1.update(first_login=False,start_time=s,end_time = e)	
		return HttpResponseRedirect('/questions/'+user_id+'')
	else:
		print "render_instruction_page"
		print user_id
		query_set = Users.objects.filter(ReceiptNumber = user_id)
		return render(request,'pradnya_2.html',{'current_user':query_set[0].TeamName})
		
@csrf_exempt		
def refresh_page(request):
	all_query_set = Users.objects.all()
	print all_query_set
	sorted_all_query_set = Users.objects.order_by('-Final_score','Total_time')
	return render(request,'partialresults.html',{'data':sorted_all_query_set})	
	#return render_to_response(template,{'data':all_query_set} ,context_instance=RequestContext(request))
	
@csrf_exempt
def final_score(request,user_id):
	print user_id
	user = Users.objects.filter(ReceiptNumber = user_id)
	return render(request,'pradnya_result.html',{'final_score':user[0]})	
	
	
		
@csrf_exempt
def render_question_page(request,user_id,question_id):
	if request.method == 'POST':
		print "POST in render_question_page"
		print "Question_id = "+str(question_id)
		print "User_id = "+str(user_id)
		get_file = 'fileField'+str(question_id)
		print get_file
		print request.FILES
		print request.FILES.keys()
		try:
			program = request.FILES[get_file].read()
		except:
			print "Error in file reading\ncheck\ncheck\ncheck\ncheck\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n.\n."
		#We got program
		
		submission_client = Users.objects.filter(ReceiptNumber = user_id)	
		submission_id = submission_client[0].TotalSubmission
		submission_id = submission_id + 1
		submission_client.update(TotalSubmission=int(submission_id))                      #got submission_id
		#we got submission_id
		
		#file_name = userid_submissionid_questionid.cpp
		filename = str(user_id) + '_' + str(submission_id) + '_' + str(question_id) + '.cpp'
		executable_name = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/AllSubmissions/' + str(user_id) + '_' + str(submission_id) + '_' + str(question_id)
		storage_path = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/AllSubmissions/' + filename
		fp = open(storage_path,'w')
		fp.write(program)
		fp.close()                                                                    #File is generated
		#File is generated
		
		
		#compiling program
		compilation_success = os.system("g++ -o "+executable_name+" "+storage_path)
		print compilation_success
		#Compilation done
		
		
		#test file1
		input_file_path = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Input/'+question_id+'/in1.txt'
		output_file_path = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Output/'+question_id+'/'+user_id+'_1.txt'
		actual_output_file_path = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Output/'+question_id+'/actual1.txt'
		
		#test file2
		input_file_path_2 = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Input/'+question_id+'/in2.txt'
		output_file_path_2 = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Output/'+question_id+'/'+user_id+'_2.txt'
		actual_output_file_path_2 = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Output/'+question_id+'/actual2.txt'
		
		#test file3
		input_file_path_3 = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Input/'+question_id+'/in3.txt'
		output_file_path_3 = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Output/'+question_id+'/'+user_id+'_3.txt'
		actual_output_file_path_3 = '/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Output/'+question_id+'/actual3.txt'
		
		
		
		if compilation_success == 0:
			print "No compilation error in "+str(question_id)+' of '+str(user_id)
			
			score_of_question1 = 0
			score_of_question2 = 0
			score_of_question3 = 0
			
			
			result1 = ""
			result2 = ""
			result3 = ""
			
			#getting time limit
			timelimit_file = open('/home/shreyas/workspace/pradnya/Backend/mywork/integrate/final1/Output/'+question_id+'/timelimit.txt')
			timelimit = timelimit_file.read()
			print timelimit
			#checking test file1
			print "Checking testfile1"
			cmd = ['python', 'pradnya_judge.py',executable_name,input_file_path,output_file_path,timelimit]
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
			out,err = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
			print "Status = "+str(out)
			if int(out) == 2:
				result1 ="Don't use fork()!! U Fucker!!"
			elif int(out) == 5 or int(out) == 4:
				result1 = "Time limit exceeded"
			elif int(out) == 6:
				result1 = "Segmentation Fault"
			elif int(out) == 1 or int(out) == 7:
				check_code = file_read(output_file_path,actual_output_file_path)
				if check_code == 1 : 
					score_of_question1 = 30
					result1 = "Correct Answer"
				else:
					result1 = "Wrong Answer"	
			else:
				result1 = "Wrong answer"			
			print "Test File1 result is --> " +result1
			
			
			
			#checking test file2
			print "Checking testfile2"
			cmd = ['python', 'pradnya_judge.py',executable_name,input_file_path_2,output_file_path_2,timelimit]
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
			out,err = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
			print "Status = "+str(out)
			if int(out) == 2:
				result2 = "Don't use fork()!! U Fucker!!"
			elif int(out) == 5 or int(out) == 4:
				result2 = "Time limit exceeded"
			elif int(out) == 6:
				result2 = "Segmentation Fault"
			elif int(out) == 1 or int(out) == 7:
				#No compilation error
				#Output file is generated
				check_code = file_read(output_file_path_2,actual_output_file_path_2)
				if check_code == 1: 
					score_of_question2 = 30
					result2 = "Correct Answer"
				else:
					result2 = "Wrong Answer"	
			else:
				result2 = "Wrong answer"
			print "Test File2 result is --> " +result2	
				
				
				
			#checking test file3
			print "Checking testfile3"
			cmd = ['python', 'pradnya_judge.py',executable_name,input_file_path_3,output_file_path_3,timelimit]
			p = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
			out,err = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE).communicate()
			print "Status = "+str(out)
			if int(out) == 2:
				result3 = "Don't use fork()!! U Fucker!!"
			elif int(out) == 5 or int(out) == 4:
				result3 = "Time limit exceeded"
			elif int(out) == 6:
				result3 = "Segmentation Fault"
			elif int(out) == 1 or int(out) == 7:
				#No compilation error
				#Output file is generated
				check_code = file_read(output_file_path_3,actual_output_file_path_3)
				if check_code == 1 : 
					score_of_question3 = 40
					result3 = "Correct Answer" 
				else:
					result3 = "Wrong Answer"			
			else:
				result3 = "Wrong answer"		
			#Finally u got the final score for that question
			#Now get it's previous score for this question
						
			user = Users.objects.filter(ReceiptNumber = user_id)
			score_list = user[0].Score_list
			submission_time_list = user[0].Submission_time_list
			print "Previous score_list of "+str(user_id)+" "+str(score_list)
			pre_sco_of_que = score_list[int(question_id)-1]
			print "Previous score of question is ",pre_sco_of_que  		
			
			score_of_question = score_of_question1 + score_of_question2 + score_of_question3
			print score_of_question
			
			if pre_sco_of_que < score_of_question :
				score_list[int(question_id)-1] = score_of_question
				final_score=sum(score_list)
				print "Final score",final_score			
				print "New score list",score_list
				
				time_req_to_solve = datetime.datetime.now() - user[0].start_time;
				secs = time_req_to_solve.total_seconds()
				submission_time_list[int(question_id)-1] = secs
				ti = sum(submission_time_list)
				user.update(Score_list=score_list,Final_score=final_score,Total_time=ti,Submission_time_list =submission_time_list)
			data = {}
			data['1'] = result1
			data['2'] = result2
			data['3'] = result3	
			data['score1'] = score_of_question1
			data['score2'] = score_of_question2
			data['score3'] = score_of_question3
			data['total'] = score_of_question
			return HttpResponse(json.dumps(data), content_type = "application/json")
			
		else:
			result = "Compilation error"
			data = {}
			data['1'] = result
			data['2'] = result
			data['3'] = result	
			data['score1'] = 0
			data['score2'] = 0
			data['score3'] = 0
			data['total'] = 0
			return HttpResponse(json.dumps(data), content_type = "application/json")
			
	else:
		print user_id
		print question_id
		if question_id == '':
			print "render_question_page where question_id = 0"
			query_set = Users.objects.filter(ReceiptNumber = user_id)
			return render(request,'pradnya_3j.html',{'current_user':query_set[0]})
			#return render(request,'pradnya_3.html',{'data':{'current_user':query_set[0].TeamName,'all_users':all_query_set}})		
		else:
			print "render_question_page where question_id = "+str(question_id)		
			return render(request,"pradnya_question_j"+question_id+".html")
		
		
