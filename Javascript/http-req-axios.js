import axios from "axios";


const getBtn=document.getElementById('get-btn');
const postBtn=document.getElementById('post-btn');

const getData = ()=>{
	axios.get('#Api-Url')
	.then(response =>{
		console.log(response);
	})
	.catch (err=> {
      console.log('Error');       
  };
};

const sendData = ()=>{
	axios
	.post('#Api-Url',{
		//Data you want to append
		//the data is converted to JSON 
	})
	.then(response=>{
		console.log(response);
	})
	.catch (err=> {
      console.log('Error');       
  };
};

getBtn.addEventListner('click',getData);
postBtn.addEventListner('click',sendData);

