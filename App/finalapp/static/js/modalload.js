$('[data-load-remote]').on('click',function(e) {
    e.preventDefault();
    var $this = $(this);
    var remote = $this.data('load-remote');
    if(remote) {
        $($this.data('remote-target')).load(remote);
    }
});

$(document).on('submit', '.login-form', function(){
$.ajax({ 
    type: $(this).attr('method'), 
    url: this.action, 
    data: $(this).serialize(),
    context: this,
    success: function(data, status) {
        $('#LoginModal').html(data);
    }
    });
    return false;
});