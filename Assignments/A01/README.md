## Assignment 1 - Getting Started
#### Due: Friday August 29th by 5:00pm
[//]: # ()

## Getting Setup

I usually discuss setting up a development environment for a first assignment, but in 1063 things are pretty simple. So we only need to address a couple of things. Both things however are super important. See below: 

### Team Chat
---

<img src="http://cs.mwsu.edu/~griffin/zcloud/zcloud-files/slack_icon.png" width="200">

The first step in doing well in any of my courses is establishing a base of communication. Why? Not everything can be done while we are in class. 

Assignments will (and should) be challenging. Therefore you will need help from me and your classmates. Using Slack provides communication well class if over. I realize that most work gets done in the evening and want to make myself available for questions. So we will use a chat client built for developers called [Slack](https://slack.com)<sup>2</sup>. You should have gotten an invite already from me. Accept it. If you didn't, ask me for another invite. [Here](https://get.slack.help/hc/en-us/articles/218080037-Getting-started-for-new-users) is a getting started guide to help you use slack. Slack is an app. It can be installed OR viewed via a web browser using a URL. 

#### Slack provides:

- Team chat (class members and myself).
- Code highlighting for snippets so we can share code and read it better.
- File sharing simply by dragging and dropping.
- Private channels so you can discuss things without everyone seeing (even I can't see).
- Polls so we can vote on things (mainly for me).

So, **NO email!** Unless I specifically ask. Slack is your communication conduit for this class.

#### Slack Recommendation

1. I **highly** recommend installing slack on your mobile device as well as your own computer. I often upload help, or code suggestions on Slack in the evening or on weekends. Having slack on your mobile device will give you the best chance of getting the `alert` or notification that something was done.
2. **The students that monitor our slack channel and participate in discussions almost alway do better. I've used slack since it was established almost 10 years ago and I can say with a high level of confidence that students who participate on Slack to better in the course.**

Now that we have our communication client set up, we probably need to start getting the actual programming environment ready! We will be doing many things from the command line this semester. Windows is not know for it's command line prowess, so we need to give it some assistance.

### VsCode (NOT Visual Studio)
---

<img src="http://cs.mwsu.edu/~griffin/zcloud/zcloud-files/vscode.svg.png" width="200">

Vscode is a lightweight editor that will also let us compile and run C++ programs. I like it much more than Visual Studio because we do not need all of what Visual Studio offers. VsCode is a more straight forward way to running C++ programs, and I think you will benefit from using it. VsCode is NOT a compiler. What does this mean? When you use Visual Studio you are using an IDE (Integrated Development Environment). The `integrated` means that many components are "integrated" within the "environment": editor, compiler, linker, library managament, debugger, team support, version control and much more. It's the kitchen sink of writing programs, and we only need an editor and compiler. The debugger is a good way of tracking down nasty problems, but we mostly debug using `cout` statements. Vscode has debug capabilities which I will touch on during the semester.

To instal VsCode, go here:
- https://code.visualstudio.com/

To add C++ support go here (don't worry about `Remote Developmen`)
- https://code.visualstudio.com/docs/languages/cpp



### Your Code Repository
---

<img src="http://cs.mwsu.edu/~griffin/zcloud/zcloud-files/github.svg" width="200">


In addition to our team chat and code editor, we need a place where we can store / retreive our code base. A `code base` is a collection of source code that is used to build a particular software system. Where `software system` in the context of class is basically our programs. Github is where you will get all of your starter code (from my repo) for each of your assignments, and it's also where you will store all of your own completed assignments. By putting all of your code on GitHub, you are basically starting a code portfolio which, if you continue to add to it after you finish my course, will allow potential employers to view your collection of programs and make you that much more marketable.


#### What is Git?

Don't let the following definitions scare you. We will use `git` and `github` at a very basic (simple) level. 

However lets define it: 

>`Git` is a distributed revision control and source code management (SCM) system with an emphasis on speed,data integrity,and support for distributed, non-linear workflows. Git was initially designed and developed by Linus Torvalds for Linux kernel development in 2005, and has since become the most widely adopted version control system for software development.<br><br>
As with most other distributed revision control systems, and unlike most client–server systems, every Git working directory is a full-fledged repository with complete history and full version-tracking capabilities, independent of network access or a central server. Like the Linux kernel, Git is free software distributed under the terms of the GNU General Public License  [[1]](http://en.wikipedia.org/wiki/Git_(software)).

So, `Git` is **distributed revision control system** (version control). This is just a fancy way of letting us manage our code. In fact, I really only want to use git so you can `push` our code to a repository that I can access so I can download and run your code. `Github` is such a place. 

>`Github` is a social site that allows programmers to share code with other programmers. It's also a great place to discover projects to work on, discover code to use in your own projects, and a great place to start a portfolio. Whereas `Git` is simply the revision control system that can be installed anywhere, and only used locally if that's the users choice. 

Remember though: `Git != Github`, Git does version control, but has commands built in to `push` your code to a repository on another computer. This other computer that we will use is `Github`. 

#### Why github for this course?

I use github as a homebase for all assignments, lectures, and resources. It's basically our courses homepage. That is why I use it. When you push your code to github, you are placing your code in a central location irregardless of what computer your working on. If you do some work in the lab, you can `push` your changes to github. If you go home, you can `pull` your changes to your home machine and continue working. If you only work on a single machine, like a laptop, then github can be your "backup" copy. 

#### Create a Github account. 
- You won't need this tutorial, but just in case:
   - https://www.wikihow.com/Create-an-Account-on-GitHub

- When you create a Github account, you must choose a `username`. 
- This is very important to remember, because you will update the class roster with this username so I know where to find all your assignments.
- Create a repository named:
    - `1063-DS-yourlastname`
    - replace the `yourlastname` with your last name to make it unique.
- Check the box that says: "Add a README.md file"

#### Edit the README.md 

- Edit the readme file on github and place your contact information inside along with a picture of YOU. NOT an avatar. NOT a thumbnail. But an easily identifiable picture of you.
- Your readme should include:
    - Your image
    - Your first and last name
    - Your email address
    - Your website (if you have one)

### Class Roster
---

![](https://d3vv6lp55qjaqc.cloudfront.net/items/220B0V0H3c041K2p251Z/google-sheets-16.png?X-CloudApp-Visitor-Id=1094421) [Class Roster](https://docs.google.com/spreadsheets/d/1jJH4T45OiY1M2zkCB3-pI1couGeZUuI1GKYriKuWq0Q/edit?usp=sharing)
#### Update the Class Roster:

- Here is a link to our class roster on google docs: ![](https://d3vv6lp55qjaqc.cloudfront.net/items/220B0V0H3c041K2p251Z/google-sheets-16.png?X-CloudApp-Visitor-Id=1094421) [Class Roster](https://docs.google.com/spreadsheets/d/1jJH4T45OiY1M2zkCB3-pI1couGeZUuI1GKYriKuWq0Q/edit?usp=sharing)

- Update the roster by adding your information to it. 

Add:

1. Your name (last, first)
2. Your email
3. Your github username<sup>*</sup>
4. A link to your 1063-DS repository<sup>*</sup>

*Your repository name and your github username are NOT the same thing.


### Rules for emailing me:
---

1) Open your email client.
2) Create a new email.
3) Put an appropriate subject in the email subject box.
4) Type a clear message that contains:
    - first name, 
    - last name,
    - course number
    - Link to any assignment that your asking about
5) Now CLOSE YOUR EMAIL CLIENT AND MESSAGE ME ON SLACK.



Sources:
- <sub>[1] http://en.wikipedia.org/wiki/Git_(software)</sub>
- <sub>[2] https://slack.com</sub>
- <sub>[3] http://www.openbookproject.net/courses/webappdev/units/softwaredesign/resources/install_python_win7.html </sub>
- <sub>[4] https://code.visualstudio.com/</sub>
- <sub>[5] https://git-for-windows.github.io/</sub>
- <sub>[6] https://www.python.org/</sub>
