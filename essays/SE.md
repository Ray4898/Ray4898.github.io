---
layout: essay
type: essay
title: may gain from the software engineering class
# All dates must be YYYY-MM-DD format!
date: 2020-05-14
labels: 
  - Software Engineering
  - Learning
  - JavaScript
  - Web development
---
How time flies！It is the end of the semester, and I am writing the last essay for the software engineering class.  I feel we are becoming a big family, and I am very reluctant to leave my classmates and professor in this class.  I am very reluctant to end this class, but all good things must come to an end.  Looking back to the whole semester, I feel I have learned a lot of things about the software engineering during the semester.  The most impressive concepts I leaned for the software engineer are the functional programing and Development Environment.

## functional programming

We learned functional programming at the beginning of the class.  Functional Programming is an amazing way to do programming.  In functional programming, we apply and compose functions to construct function.  We don’t need to write a big long for loop or while loop to operate, calculate control any objects or variables in a list; instead we use underscore function to do shortcut operation.   For example, in JavaScript, if we want to find the sum of a list of the number, we can use “for loop.” Then, we can make a function like below:

```
function sun(array) {
 let Sum =0
for( let i=0; i<array.length; i++ )
	Sum = sum +array[i]; 
}  

```

However, if we use underscore functional programming, we can calculate the sum with just one line of code.  We can use “var sum = _.reduce([1, 2, 3], function(memo, num){ return memo + num; }, 0);”  Therefore, we can skip the for loop if we use functional programming.  

<img class="ui small floated image" src="../images/fp.PNG">
Functional programming is very useful in web application development.  When developing a web, we always need to get the data from the database and filter the data to get what we want.  With functional programming, we can skip a lot of for loop to speed up our coding, and we can combine some underscore functions together to make a function that return what we want.  It is very useful when we want to get and filter the data from the database.  

Besides that, since we do not need to do the design a large for loop, functional programming can reduce the error we may have.  Hence, functional programming is very useful for software engineering. 

In my final project, I have used a lot of functional programming to filter data and map the data into individual list.  It would be complicate if I use for loop for each function instead of using functional programing.  This is the first time I can see the advantage of the functional programming.

## configuration management

<img class="ui small floated image" src="../images/git.PNG">
Configuration management identifies and keeps track of all relevant elements of the configuration of a system.  For example, GitHub is the tool to do the Configuration management.   GitHub can do the version control, and it can check and store the update and change online without manually maintain the backup.  We can use GitHub to switch among different versions of the files quickly by using branch since it just detects and load the difference.

Before taking this class, I had heard about the GitHub.  This class let me understand what the GitHub really is.  GitHub is an amazing tool for software engineers.   We can create repository and link that to a local directory.  The best feature I like most about the GitHub is we can create branch from the master branch of the repository.  If we do not want to mess up the master branch when adding new things to the project, we can just create another branch form the master and edit from the new branch.  The edit we made in the new branch will not affect the master branch, so we can do whatever we want in the new branch without worry about the master branch.  If we are satisfied with the change we made in the new branch, we can merge the new branch to the master.   If we do not like the change we made, we can just delete the new branch, and everything remain unchanged.  Therefore, we can keep improving our application without messing up the application itself.

In addition, GitHub stores everything online and allows more than one person to edit the files, so it is very useful for a team to do a project.  When doing a project, we can break down the works and assign different tasks to different team member.  Each team member can create his or her own branch from the master and work on the project parallelly.   Therefore, all team members can work on the project at the same time without waiting for the others, so GitHub reduce the required time to finish a project.

## Development Environments

Development environment is very important for software engineering.  It is the platform for the software engineer to build project and write code.  When we need to build a web application, we always need it.

<img class="ui small floated image" src="../images/ij.PNG">
For this semester, we used IntelliJ as our development IDE.  I used to use visual studio as my development IDE platform; however, after I learned about the IntelliJ, I have fallen in love with this new IDE platform.  I feel the IntelliJ is mush easier to use than Visual Studio.  When using the Visual Studio, I need to build and public solution for each time I edit the code; however, I do not need to do that in the IntelliJ.  After I edit the files in the IntelliJ, the web application will update automatically, and I can see the change on the web page immediately.   Therefore, IntelliJ is very useful for debugging the error.  IntelliJ may be more useful than Visual Studio when developing a web application since we may want to see if our code work immediately after we add or edit a function.  I think I may use IntelliJ more than Visual Studio in the future when developing a web application.

## conclusion

From this class “software engineering,” I leaned a lot of things for the software engineering.  Although we just focus on the web application development, I think the things we learned in the class will also help us become a good engineer.
