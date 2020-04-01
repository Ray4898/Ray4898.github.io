---
layout: essay
type: essay
title: "final-project-idea: UH Q&A Chegg platform"
date: 3/31/2020
labels:
  - Software Engineering
  - Meteor
---


## Overview
The problem: A lot UH students will have a lot of questions on their homework, quiz, lectures and so on.  When they have problems or questions, they can just ask their professors by sending emails or asking them face to face in their office hours; however, asking for help by email is not very efficient, and many professors may not be busy to check the emails.  Also, it is not easy to describe some problems in text, so the professors probably don’t understand what we want to ask.  We also can go to their office to ask questions in office hours, but the office hours for many professors are very short.  We may have another class or work during their office hours, so it is hard for some people to ask questions during their professors’ office hours.  
Beside the professor, we also can ask the classmates, but not too many students have strong connection and communication with their classmates, and they don’t event know what their names are.  In addition, the classmates we ask probably don’t know the answers too.  
Some classes would use some social media for the communication, such as slack. We can ask question thru this social media, but this is limited in a class. We cannot ask other problems that is not related to the class there. 
The last way to ask the questions is using internet.  We can google the answer online, but it is also not easy to find the problem we want to ask online. Sometimes, we may need to spend a lot of time to find the problem. Some resources online are not free.    
The solution: The UH Q&A platform is an online platform that allows UH students from different major to post the questions or problems online, and the other students or professors who may know the answer can answer the questions. 

## Approach
This project is similar to Chegg, except for the following:
•	This online platform is free
•	This online platform is only for UH students and faculty.
•	Beside the text and picture, people also can upload the video to this platform.
•	People also can schedule an online meeting.
•	This is also a live chat.
When designing your version of this application, keep the following in mind:
Role: There would be three roles in this system: admin, students and faculty. Administrators are special users who monitors the behavior of users in the system and create new major and other functionality. Students are UH students.  They can choose their major, interest, and even the course title, and they can post the questions, discussions, the answer, and solution in this system based on the major or course title.  Faculty are the UH faculty, and they can post the answers to answer the questions from the students online.

Major: This would be the major based on the UH system. People can filter the solution, discussion or problems based on the Major. Students can also post their question on the special major.
Course title: This is the course title based on the UH courses. Students can filter the solutions, discussion or problems based on the course title. Students can also post their question for the special course.
Keyword: People can filter the solution, discussion or problems based on the Keyword. Students can also post their questions or discussions and set some keywords for them.

Search: There would be a search box for the people to search the questions and solutions. 

Checkmark: After the students who answer the question get the solution by other people, and they are satisfied it, they can check the checkmark indicating the questions are solved. The solved problems would not be deleted just for the other people who may have the same problems. 
Initially, images and video can be specified as URLs, but for the final version, people would be able to upload text, image or video to this system.
Live chat and online meeting: Initially, we can use zoom to do the meeting.  For the final version, there should be an option for the live chat and online meeting. People can just click on the other user to start the chat or meeting.  People also can schedule an online meeting. 

Ideally, we should link the user’s account to their emails or phones. When their questions are solved, we can send them a notification email.


Some possible mockup pages include:
<br>
•	Landing page
<br>
•	User home page
<br>
•	Admin home page
<br>
•	User Profile page
<br>
•	Login page
<br>
•	List questions page
<br>
•	Create question page
<br>
•	Chat page
<br>
•	Search question page
<br>
•	Question page
<br>
•	Register page

## Use case ideas

•	New user goes to landing page, register, logs in, gets home page, sets up profile. <br>
•	Admin goes to landing page, logs in, gets home page, edits site.<br>
•	User goes to landing page, logs in, get home page. <br>
•	In the home page, they click on different buttons to go to search page, list questions page, and create questions page. <br>
•	User can click on each question to go to the question page.<br>
•	User can post the solution in the question page.<br>
•	The chat page is a small pop up window appearing on the corner of the web page, which allow people to send the real time messages and communicate with others. 

## Beyond the basics

After implementing the basic functionality, here are ideas for more advanced features:<br>
•	Use UH CAS Login instead of Meteor Login to guarantee that users are UH students.<br>
•	A rating system for the answer and solution.<br>
