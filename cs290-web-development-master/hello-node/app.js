var express = require('express');
var db = require('./dbtest.js');
var session = require('express-session');

var app = express();

app.use(session({secret: 'L4fk5OPc34'}));

app.set('port', process.env.PORT || 3000);

app.get('/', function(req, res){
	var sess = req.session;
	var views = req.session.views || 0;
        var responseContent = '';
        res.type('text/plain');
        responseContent += 'Welcome to CS290 Node.JS!\n';
	responseContent += 'You have visited this page ' + views + ' times before. If this increments on refresh, sessions are working.\n';
	req.session.views = views + 1;
        db.dbtest().then( function createResposne(val){
                responseContent += val;
                res.send(responseContent);
        });
});

app.use(function(req, res, next){
        res.type('text/plain');
        res.status(404);
        res.send('404 - There is nothing here save for vast expanses of nothing'                                                       );
});

app.listen(app.get('port'), function(){
        console.log( 'Express started on http://localhost:' + app.get('port') +                                                        ' press Ctrl-C to exit' );});

