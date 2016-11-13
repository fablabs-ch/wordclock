// Taken from: http://stackoverflow.com/questions/3226971/how-to-load-the-contents-in-the-text-file-or-the-html-codes-in-a-html-file-to-a
function download_to_textbox(url, el)
{
    $.get(url, null, function(data)
        {
            el.val(data);
        }, "text");
}

function preview_layout(){
  var params={
    grid:$('textarea[name="grid"]').val()
  };
  $.post('/generate-layout/', params, function(data){
    data.ownerDocument = document;
    $('#preview_txt').html(data);
  }, 'text');
}
