

var seconds_left = ;
var interval = setInterval(function() {
    document.getElementById('timer_div').innerHTML = --seconds_left;

    if (seconds_left <= 0)
    {
        document.getElementById('timer_div').innerHTML = 'You are ready';
        clearInterval(interval);
    }
}, 1000);


