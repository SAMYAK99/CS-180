//DATA LAYER
//create an object named issueList
var issueList = {
	issues: [],

	displayIssues: function () {
		//if issues array is empty, there is no issue in the issues list
		if(this.issues.length === 0) {
			console.log('There is no issue in the issues list');
		}
		else {
			var issueWithCompletedStatus = '';
			console.log('My Issues : ');
			for(var i = 0; i < this.issues.length; i++) {
				var issue = this.issues[i];

				if(issue.completed === true) {
					issueWithCompletedStatus = '(X)-' + issue.issueName;
				}
				else {
					issueWithCompletedStatus = '()-' + issue.issueName;
				}
				console.log(issueWithCompletedStatus);
			}
		}
	},
	
	addIssue: function(newIssue){
		this.issues.push( {
			issueName: newIssue,
			completed: false
		});
		this.displayIssues();
	},

	changeIssue: function(position, newIssue) {
		this.issues[position].issueName = newIssue;
		this.displayIssues();
	},
	
	deleteIssue: function(position) {
		this.issues.splice(position, 1);
		this.displayIssues();
	},
	
	toggleComplete: function(position) {
		var issue = this.issues[position];

		//changed the status of the object
		issue.completed = !issue.completed;
		this.displayIssues();
	},
	
	toggleAll: function() {
		var totalIssues = this.issues.length;
		//Get the total completed issues
		var completedIssue = 0;

		for(var i = 0; i < totalIssues; i++) {
			if(this.issues[i].completed === true) {
				completedIssue++;
			}
		}
		//Case 1: If all the issues are completed, make them incomplete
		if(totalIssues === completedIssue) {
			for(var i = 0; i < totalIssues; i++) {
				this.issues[i].completed = false;
			}
		}
		//Case 2: Otherwise make them complete
		else {
			for(var i = 0; i < totalIssues; i++) {
				this.issues[i].completed = true;
			}
		}
		this.displayIssues();
	}

};


//HANDLER OBJECT
var handlers = {
    displayIssues: function() {
        issueList.displayIssues();
    },
    toggleAll: function() {
        issueList.toggleAll();
    },
    addIssue: function() {
        var issueText = document.getElementById('issueText');
        issueList.addIssue(issueText.value);
        view.displayIssues();
        issueText.value = '';
    },
    changeIssue: function() {
        var changeIssuePositionInput = document.getElementById('changeIssuePositionInput');
        var changeIssuetextInput = document.getElementById('changeIssuetextInput');

        issueList.changeIssue(changeIssuePositionInput.valueAsNumber, changeIssuetextInput.value);
        view.displayIssues();
        changeIssuePositionInput.value = '';
        changeIssuetextInput.value = '';
    },

	deleteIssue: function(position) {
		issueList.deleteIssue(position);
		view.displayIssues();
	},

    toggleComplete: function() {
        var toggleIssuePositionInput = document.getElementById('toggleIssuePositionInput');
        issueList.toggleComplete(toggleIssuePositionInput.value);
        view.displayIssues();
        toggleIssuePositionInput.value = '';
    }
};

//VIEW LAYER
var view = {
    displayIssues: function() {
        var issueUl = document.querySelector('ul');

        //clear the UL 
        issueUl.innerHTML = '';

        var issueWithCompletedStatus = '';

        //count the issues and then display
        for(var i=0; i< issueList.issues.length; i++) {
            var issueLi = document.createElement('li');
            var issue = issueList.issues[i];

            if(issue.completed === true) {
                issueWithCompletedStatus = '(X)-' + issue.issueName;
            }
            else {
                issueWithCompletedStatus = '()-' + issue.issueName;
            }

			//assign an id to the list item
			issueLi.id = i;

            //display the name of the issue
            issueLi.textContent = issueWithCompletedStatus;

			//aapend the delete button in the list item
			issueLi.appendChild(this.createDeleteButton());

            //add the list in the UL
            issueUl.appendChild(issueLi);
        }
    },

	createDeleteButton: function() {
		var deleteButton;

		deleteButton = document.createElement('button');
		deleteButton.textContent = 'X';
		deleteButton.className = 'deleteIssue';
		var styleButton = "float: right;  width: 30px; height: 30px;";
		deleteButton.setAttribute('style', styleButton);
		return deleteButton;
	},

	setUpEventListener: function() {
		var issueUl = document.querySelector('ul');
		issueUl.addEventListener('click', function(event) {
		//get the target element that is clicked
		var elementClicked = event.target;

		//check if the element clicked is deleteButton 
		if(elementClicked.className === 'deleteIssue') {
			//call handlers deletion method here
			handlers.deleteIssue(parseInt(elementClicked.parentNode.id));
		}
	});
	}
};

view.setUpEventListener();


