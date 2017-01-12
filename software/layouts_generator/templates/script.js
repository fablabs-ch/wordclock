// Taken from: http://stackoverflow.com/questions/3226971/how-to-load-the-contents-in-the-text-file-or-the-html-codes-in-a-html-file-to-a
function download_to_textbox(url, el)
{
    $.get(url, null, function(data)
        {
            el.val(data);
        }, "text");
}

function preview_layout(){
  $('#preview_txt').html("Loading...");
  var list = ['grid', 'hs', 'vs', 'hm', 'vm', 'ff', 'fs', 'fw'];
  var params = {};
  list.forEach(function(v){
    params[v] = $('*[name="'+v+'"]').val()
  });
  params.grid = params.grid.split('\n').join('\r\n');
  $.post('/generate-layout/', params, function(data){
    $('#preview_txt').html(data);
  }, 'text');
}
