console.log("about to fetch a rainbow");
    

    catchApi()
    .then(response =>{
        console.log("yay!!");
    })
    .catch(error=>{
        console.log("error!!");
        console.error(error);
    });

    async function catchApi(){
      const response= await fetch("#api-url");
      const blob= await response.blob();
      document.getElementById("API").src=URL.createObjectURL(blob);
    }