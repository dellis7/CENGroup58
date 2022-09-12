# Syllabuster

Syllabuster creates a suggested syllabus for a course that is a result of the expressed topics of interest from the students, and the teacher’s initial syllabus plan. Before the start of the semester, students create an account with Syllabuster, where they will submit the list of topics they are interested in learning about from the course. The course instructor also creates an account with Syllabuster, and submits the topics he/she had in their initial syllabus. Once inputs from both parties are received, Syllabuster runs a matching and ranking algorithm that compares the topics from the students with those from the teacher. The topics that appear in both the student and teacher inputs are ranked in descending order of frequency of occurrence. Those not suggested by both parties are not outputted in the final syllabus. Now, the students and teachers can view the final outcome of Syllabuster’s algorithm.

## Authors

- Beatrice Ndalichako
- Deven Ellis
- Zhiqin Qu
- Viraj Chandrasekaran

## Documentation

### Sign Up interface

When the user opens Syllabuster, they will be met with the Sign up interface. There are input fields where the user will enter their credentials, such as full name, UFL email address, password, and indicate whether they are a student or a teacher. Once all information is entered, the user clicks the “Create Account” button which will send the entered data to the users database, if the entries in the “New password” and “Confirm password” fields match. The sign up interface has a link that leads to the sign in interface, for returning users to use for logging in.


### Sign In interface

The sign in interface is for returning users who have already created an account with syllabuster. There are two input fields where the user enters their UFL email address, and their registered password. Then the user clicks the “Sign In” button to get access to their account. Clicking the sign button invokes a C++ function that searches for the entered email address and password in the database of registered users. If the email address does not exist in the database, or the email address exists but the password entered does not match the password in the database, an error message will be displayed prompting the user to try again. If the email address and matching passwords are found in the database, the user will be directed to the main dashboard of Syllabuster. There is a link at the bottom of the interface for first time users, who have not created an account, that will redirect the user to the sign up interface.

### The main dashboard

The dashboard allows signed in users to enter their topics inputs, view the final syllabus, and sign out of Syllabuster. At the top-right corner, the name of the current user is displayed. When the user clicks on the “Suggest syllabus topics” button, they will be redirected to the form interface that takes in the topics inputs from the users. When the user clicks the “View Final Syllabus” button, a C++ function checks whether inputs have been received from both the students and the teacher. If yes, the user’s device will display a .txt file with the results of Syllabuster’s algorithm. Otherwise, an error will display on the interface to let the user know that input from both students and the teacher are required before outputting the final syllabus. When the user click the “Sign out” button, they will be redirected back to the sign in interface.

### The topics input form

The topics input has the top entry field, where the user will type in a topic that they are suggesting for the syllabus. Then, the user clicks the “Add button”, which registers the topic entry to the bottom field. This field hosts all entries by the user in the current session, before they are submitted to the respective database, students' topics vs teacher’s topics, after the user clicks the “Submit” button. There is a “Go back to dashboard” button that redirects the user to the main dashboard.


## Run Locally

An IDE with the capabilities to view and edit a FireMonkey form (.fmx file) is required to run our source code. We recommend installing C++ Builder to compile and run our code. Once installed, please place our source code files in the “Embarcadero\Studio\Projects” directory, and open this folder in the C++ Builder IDE. Now, you should be able to view, edit, compile, and run source code.
Also, make sure to add column headings for your database files, before inputting and outputting them from your machine. Without the headings, the database skips the first row when the first input is added, which causes an exception to be thrown when reading data from the database since the request returns an empty row.

