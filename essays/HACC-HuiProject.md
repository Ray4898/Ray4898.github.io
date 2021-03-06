---
layout: essay
type: essay
title: The HACC-Hui Website Development Project for ICS 414
# All dates must be YYYY-MM-DD format!
date: 2020-12-12
labels: 
  - Hawaii Annual Code Challenge
  - Software Engineering
  - Learning
  - Web application developement
  - React
  - Meteor
  - MongoDB
---
During the Fall 2020, I was very excited to participate in the HACC-Hui Website Development Project to design and build a website for the HACC-Hui participants.  I am also very happy to see that we built the website successfully, and people who used the website were satisfied with the website we built.  

## What is HACC-Hui?

HACC-Hui is the website we designed and built to simplify team formation and ongoing team management for the HACC.  HACC stands for Hawaii Annual Code Challenge, and it is an event that provides an opportunity for the participants to solve the real-world challenges and the problems which the Hawaii state and the companies or schools in the state facing to with some creative technical solutions.  For more HACC information, please go to the <a href="https://hacc.hawaii.gov/">HACC website</a>.  There are three different roles for the HACC-Hui website: minor participant, regular participant, and administrator.  Participants need to go the Slackbot to register the HACC-Hui accounts to login to that page.  For the first time when the participants sign into the HACC-Hui website with their accounts, the website will ask them is they are under 18 yeas old.  If a participant is under 18 years old, the participant is considered as a minor participant, and he (she) need to get the approvement from his (her) parents before participating in this HACC event.   The regular participants need to fill out their profile first, such as the skills they have and the tools they know.  Participants can create teams for different HACC challenges with the required skills and tools which they can pick from a list of available skills and tools in the team creation form.  Participants also can view all the teams, find the teams they want, and send the join-team request to the owners of the team, and then, the owners of the team can either accept or decline the request.   Administrators can manage the website and the teams, and they can add more challenges, necessary skills, and tools to the database through the website, so participants can have more options to chose for the challenges they are interested in, the skills they have, and the tools they know when filling out their profile and creating teams.  Administrators can also change the eligibility status of the minor participant.  If they receive the approval emails from the parents or guardians of the minor participants, administrators can change the status of the minor participants from ineligible to eligible so that the minor participants can participant in the HACC projects.  To build this website, we used meteor as the JavaScript web framework, and we used semantic-UI React for the UI design and MongoDB as the backend database.
For more information about HACC-Hui website, please go to the <a href="https://hacchui.ics.hawaii.edu/#/">HACC-Hui website</a> and the <a href="https://hacc.hawaii.gov/wp-content/uploads/2020/10/HACC-Hui.pdf">instruction PDF of the HACC-Hui</a>

## What did I do for this HACC-Hui project?

Developing the HACC-Hui web application was not an easy project, and we only had around two months on the project.  We divided this project into four millstones.  At the beginning, we made seven teams.  Each team worked on the same millstone of the project, and we picked the best one as the actual website.  However, we found out it was hard to pick the best one since every team had the good parts and bad parts in its designed website.  It was also hard to merge the good parts of the website each team designed and built together since every team had a different design method, and we did not have too much time on this project.  Therefore, we later decided to divide this HACC-Hui website project into many small issues, and everybody participating in this project could pick one or more issues to do it.  At the end, we merged the work from all the people to complete our web application.  Therefore, everybody would work and contribute on different parts for this project, so we were able to finish it on time.

For this project, first, I worked on a page called best-fit-pages for the HACC-Hui website.  The best-fit-page allows participants to see all available teams from the MongoDB database, and this page displays all the team information for each available team from the database, including the name of the team, the challenge the team want to work on, the skills and tools the project and the team require, the GitHub website for the team, the team members, and the Join button that allow the participant to click to send request to join the team.  Besides that, I also implemented a dropdown function that allows the participant to sort and view the teams in an order from the best match to less match based on their interested challenges, their skills, or the tools they know.  Figure 1 shows the best fit team page webpage.  After you log in to the website as a participant, you can see this page by clicking the Open Teams tap on the top menu. 

<div class="ui large rounded images">
  
 <img style="margin-left:100px;" class="ui large center image" src="../images/best-fit-pageweb.PNG">
 <header><h3 style="margin-left:50px;">Figure 1. The best fit team page</h3></header>
</div>
The second thing I did for the website was to improve the existing “Request to Join” button in the best-fit-page webpage.   Some people had implemented the “Request to Join” button in the best-fit-page webpage before I modified the button; however, the “Request to Join” button they implemented did not become unclickable as it was supposed to be after a participant click on that button, and there was not any notification after they click on the button.  Therefore, I worked with Isaac, another student participant in this project, to fix this problem.  We made the webpage to show a nice, sweet alert popup after clicking on the “Request to Join” button.  We also made that after clicking on the button, the button become unclickable and display “You sent the request” until the owner of the team response to the request.  Figure 2 belew the screenshot for how the button change before and after clicking on the button.

<div  class="ui large rounded images">
  
 <img style="margin-left:100px;" class="ui large center image" src="../images/beforejoining.PNG">
 <img style="margin-left:100px;" class="ui large center image" src="../images/Joining.PNG">
  <img style="margin-left:100px;" class="ui large center image" src="../images/Joined.PNG">
 <header><h4 style="margin-left:50px;">Figure 2. screenshot showing how the button change before and after clicking on the button</h4></header>
</div>

The third one I contributed on this website was to implement a webpage for the administrator to view all the unconsented minor participants and be able to change the eligibility status of the minor participants.  This page shows the information of all the unconsented minor participants, including their names, parent names, and emails.  I used the grid to show the information on this website.  The first column shows the name of the unconsented minor participants, and the second column shows the parents’ names of the unconsented minor participants.  I also added a third column for the compliant option, and there is a checkbox on this column for each unconsented minor participant.  Administrator can check the checkbox and click the submit button to change the unconsented minor participants to consented minor participants, so they can participant in the HACC projects.  Figure 3 shows the screenshot of the unconsented-minor-participants page. 

<div class="ui large rounded images">
  
 <img style="margin-left:100px;" class="ui large center image" src="../images/UpdateMinorp.PNG">
 
 <header><h3 style="margin-left:50px;">Figure 3. unconsented-minor-participants page</h3></header>
</div>

In additions, I also made the best-fit-team page become mobile friendly, so people can view the webpage clearly on their phones or tablets.  I also changed the style of the best-fit-team page and the unconsented minor participants page so that they can match the style of the rest of the webpages on this web application.  

## How was my team and who I worked with?

For the first two millstones of this project, I worked with a team, and the other team members were Nathan, Ty, and Kyle.  We used discord to communicate and used GitHub to share and show our work on this project.  We also shared any our idea of the website design.  For each milestone, we made some issues with GitHub, and each of the team member could pick one and work on it.  When we finished our issues, we merged all our work together.  We also helped each other when someone in our team got stuck or had some problems.  
For the first millstone, I picked the profile page issue and made a webpage that allows the participants to fill in their profiles when they sign into the website at the first time.  For the second millstone, I picked the best-team page issue and made a webpage to show the best match teams based on the participants’ interested challenges, skills, and toolset they have.  
  
After the second millstone, Professor Moore changed the way we built the website to increase the efficiency.  He dismissed the teams and made a lot of issues for this project, and everyone could pick one or more issues to work on it (them) individually.  Therefore, after the second millstone, I did not have a team anymore, or we can say there was only one team, and the team members for the team were all people working on the project.  During this time, since I work independently for most of the issues I picked, I did not communicate with too many other people.  The only person I worked with during this period was Isaac, and he asked me for help on improving the “Request to Join” button issue.  I communicated with him through the discord, and we also worked together to figure out how to modify the WantToJoinCollection API for this issue.  Later, I also asked him to test the best-fit-team webpage I made.

## what do I think of and learn from this project and this course?

I think we were doing a good job on this project.  At the beginning, I worried if we were able to finish this project since we only had two months on it, and we needed to implement a lot of functions and webpages for the web application.  However, we did it, and the people who used our web application did not compliant about our website.  I am very happy that everybody who participated in this project were working hard on this project, including me.  

I also want to thank ICS 414.  I really enjoyed in this course ICS 414. This course is very different from the other regular courses because this course does not have too many lectures, tests, and homework.  However, this course gave me the opportunity to apply the things I learned in ICS 314 to work on a real-world project for the client, so I was able to gain the real-world experience in developing a website.  Although this course mainly focuses on the project, I still learned a lot of things by building the web application.  When working on the project, I basely needed to figure out the solutions by myself when facing some new problems which I had never seen before.  I also needed to search and learn the new things online on my own, which I had never seen before.  However, I think these are the things we need to do when working for a company in the future.  When we start working after graduation, we will be facing a lot of new things we never learn in the school; however, the old staffs will probably just introduce the new things a little bit.  Therefore, we need to know how to use the available online resource to learn new things very quickly.  I also think it will be harder for me to forget the things I figure out by myself than the thing I learn through the lectures.  The way I figure out on my own to solve a problem always impress me more, so I will solve the same problem quickly when I see the same problem again.  In additions, I also learned how to work with a team and communicate with the other team members during the project.  Overall, ICS 414 made me gain a lot of soft skills which the other courses would not be able to give me.  I hope UH can offer more course like ICS 414.  

Source: <a href="https://github.com/HACC-Hui/HACC-Hui"><i class="large github icon "></i>source code for the HACC-Hui</a>

