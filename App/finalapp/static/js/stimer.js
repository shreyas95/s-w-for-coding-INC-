var time_left;
$(document).ready(function (){
	$.ajax({
    url: '/timer',
    success: function(response) {
    	console.log("success");
         time_left=response.time_left;
    },
    failure:function(d){console.log("failure");}
});
});
 Number.prototype.toHHMMSS = function () {
    var sec_num = parseInt(this, 10); // don't forget the second param
    var hours   = Math.floor(sec_num / 3600);
    var minutes = Math.floor((sec_num - (hours * 3600)) / 60);
    var seconds = sec_num - (hours * 3600) - (minutes * 60);

    if (hours   < 10) {hours   = "0"+hours;}
    if (minutes < 10) {minutes = "0"+minutes;}
    if (seconds < 10) {seconds = "0"+seconds;}
    var time    = hours+':'+minutes+':'+seconds;
    return time;
}
setInterval(function()
	{$('#timer').html(time_left.toHHMMSS());time_left--;},1000)
