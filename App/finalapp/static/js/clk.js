	
var counter=setInterval(timer, 1000);
function timer()
{
  if(!localStorage.count)
	{
	localStorage.count=60;
	}
else{
	localStorage.count=Number(localStorage.count)-1;
}
  if (localStorage.count <= 0)
  {
     clearInterval(counter);
     return;
  }

 document.getElementById("time_header").innerHTML=localStorage.count + " secs"; 
}
