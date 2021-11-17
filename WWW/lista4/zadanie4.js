$( function() {
    var dialog, form,
      imie = $( "#Imie" ),
      nazwisko = $( "#Nazwisko" ),
      miasto = $( "#Miasto" ),
      kod = $( "#Kod" ),
      data = $( "#Data" ),
      allFields = $( [] ).add( imie ).add( nazwisko ).add( miasto ).add( kod ).add( data ),
      tips = $( ".validateTips" );
      
    function addUser() {
      allFields.removeClass( "ui-state-error" );

        $( "#users tbody" ).append( "<tr>" +
        "<td name="+imie.val() + nazwisko.val() +miasto.val() +kod.val() +data.val() +">" + imie.val() + "</td>" +
        "<td name="+imie.val() + nazwisko.val() +miasto.val() +kod.val() +data.val() +">" + nazwisko.val() + "</td>" +
        "<td name="+imie.val() + nazwisko.val() +miasto.val() +kod.val() +data.val() +">" + miasto.val() + "</td>" +
        "<td name="+imie.val() + nazwisko.val() +miasto.val() +kod.val() +data.val() +">" + kod.val() + "</td>" +
        "<td name="+imie.val() + nazwisko.val() +miasto.val() +kod.val() +data.val() +">" + data.val() + "</td>" +
        "<td name="+imie.val() + nazwisko.val() +miasto.val() +kod.val() +data.val() +">" + "<a href=# id="+imie.val() + nazwisko.val() +miasto.val() +kod.val() +data.val() +">Usuń</a>" + "</td>" +
        "</tr>" );
        dialog.dialog( "close" )
    
    }
 
    dialog = $( "#dialog-form" ).dialog({
      autoOpen: false,
      height: 400,
      width: 350,
      modal: true,
      buttons: {
        "Stwórz profil": addUser,
        Wróć: function() {
          dialog.dialog( "close" );
        }
      },
      close: function() {
        form[ 0 ].reset();
        allFields.removeClass( "ui-state-error" );
      }
    });
 
    form = dialog.find( "form" ).on( "submit", function( event ) {
      event.preventDefault();
      addUser();
    });
 
    $( "#create-user" ).button().on( "click", function() {
      dialog.dialog( "open" );
    });
  } );

  $( function() {
    $( "#dialog-confirm" ).dialog({
      resizable: false,
      height: "auto",
      modal: true,
      buttons: {
        "Tak": function() {
            
          $( this ).dialog( "close" );
        },
        Nie: function() {
          $( this ).dialog( "close" );
        }
      }
    });
  } );