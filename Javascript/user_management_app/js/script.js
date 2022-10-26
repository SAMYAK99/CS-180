
//data layer
let usersData = {
    admin: {
        adminEmail: 'admin@gmail.com',
        pwd: 'admin@123',
    },

    users: {

    }
}

//handlers object
let handlers = {
    registerData: function() {
        let name, contact, email, password;

        let form = document.querySelector('form');

        form.action = "#";

        name = document.getElementById('name').value;
        contact = document.getElementById('contact').value;
        email = document.getElementById('emailText').value;
        password = document.getElementById('passwordText').value;

        //create an array of objects;
        let userDataArray = new Array();
    
        userDataArray = JSON.parse(localStorage.getItem(usersData.users)) ? JSON.parse(localStorage.getItem(usersData.users)):[];

        if(name != "" && contact != "" && email != "" && password != "") {
            //check for duplicate data entry which are already stored in the localstorage
            if(userDataArray.some((record) => {
                return record.email == email})) {
                    alert("OOPS! The email is already taken. Please, enter a unique email id");
            }
            else {
                if(name === null) {
                    alert("Please, enter a valid name.");
                }
                else if(!(email.includes('@'))) {
                    alert("Please, enter a valid email id");
                }
                else if(contact === null || isNaN(contact) === true || contact === 0 || contact.length < 10) {
                    alert("Please, enter a valid contact. Contact must be equal to or greater than 10 digits");
                }
                else if(password === null || password.length < 5) {
                    alert("Password length must be greater than 5.");
                }
                else {
                    userDataArray.push({
                        "name":name,
                        "contact":contact,
                        "email":email,
                        "password":password
                    })
                    localStorage.setItem(usersData.users, JSON.stringify(userDataArray));
                    
                    form.action = "/index.html";
                }
            }            
        }

    },

    loginUser: function() {
        let email, password;

        email = document.getElementById('emailText').value;
        password = document.getElementById('passwordText').value;
    
        //create an array of objects;
        let userDataArray = new Array();
    
        userDataArray = JSON.parse(localStorage.getItem(usersData.users)) ? JSON.parse(localStorage.getItem(usersData.users)):[];
        
        let currentUser;

        //check whether the entered login credentials are valid or not
        if(userDataArray.some((record) => {
            return record.email == email && record.password == password})) {

                currentUser = userDataArray.filter((record) => {
                    return record.email == email && record.password == password})[0]
                    localStorage.setItem("name", currentUser.name);

                let form = document.querySelector('form');
                form.action = "/userDashboard.html";
        }
        //for admin
        else if(usersData.admin.adminEmail == email && usersData.admin.pwd == password) {
            
            let form = document.querySelector('form');

            localStorage.setItem("name",'Admin');

            form.action = "/adminDashboard.html";

            //display the records
            view.displayUserData();

        }
        else {
            alert("OOPS! The email id/passowrd is incorrect.");
        }
    },

    logoutUser: function() {
        localStorage.removeItem('name');
        alert("Hope to see you again...");
        window.location.href = "/index.html";
    }
};

//view layer
let view = {
    displayUserData: function() {
        document.getElementById("usersDataTable").innerHTML = "";
        //create an array of objects;
        let userDataArray = new Array();
    
        userDataArray = JSON.parse(localStorage.getItem(users.usersData)) ? JSON.parse(localStorage.getItem(users.usersData)):[];

        if(userDataArray) {
            for(let i = 0; i < userDataArray.length; i++) {
                let usersNewDiv = document.createElement('div');
                usersNewDiv.className = "row";
                console.log(userDataArray[i].name);
                usersNewDiv.innerHTML = '<div class="col">'+userDataArray[i].name+'</div>' +
                
                '<div class="col">'+userDataArray[i].contact+'</div>' +
                '<div class="col">'+userDataArray[i].email+'</div>';
                
                document.getElementById("usersDataTable").appendChild(usersNewDiv);
            }
        }
    }
};