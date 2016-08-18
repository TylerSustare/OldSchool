var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false}));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3000);

app.get('/', function(req,res){
  res.render('home.handlebars') // can omit the .handlebars, but it's available
});

app.get('/get-post', function(req,res){
  var qParams = [];
  for (var p in req.query){
    qParams.push({'name':p,'value':req.query[p]})
  }
  var context = {};
  context.dataList = qParams;
  context.reqType = "GET";
  res.render('get-post',context);
});

app.post('/get-post',function(req,res){
  var qParams = [];
  for (var p in req.body){
    qParams.push({'name':p, 'value':req.body[p]})
  }
  console.log(qParams);
  console.log(req.body);
  var context = {};
  context.dataList = qParams;
  context.reqType = "POST";
  res.render('get-post',context);
});

app.get('/show-data',function(req,res){
  var context = {};
  context.sentData = req.query.myData;
  res.render('show-data',context);
});

/*
app.get('/get-loopback',function(req,res){
  var qParams = "";
  for (var p in req.query){
    qParams += "The name " + p + " contains the value " + req.query[p] + ", ";
  }
  qParams = qParams.substring(0,qParams.lastIndexOf(','));
  qParams += '.';
  var context = {};
  context.dataList = qParams;
  res.render('get-loopback',context);
});

app.get('/get-loopback-improved', function(req,res){
  var qParams = [];
  for (var p in req.query){
    qParams.push({'name':p,'value':req.query[p]})
  }
  var context = {};
  context.dataList = qParams;
  res.render('get-loopback-improved',context);
});

app.post('/post-loopback',function(req,res){
  var qParams = [];
  for (var p in req.body){
    qParams.push({'name':p, 'value':req.body[p]})
  }
  console.log(qParams);
  console.log(req.body);
  var context = {};
  context.dataList = qParams;
  res.render('post-loopback',context);
});
*/

app.get('/other-page', function(req,res){ // address
  res.render('other-page'); // view
});

function genContext(){
  var stuffToDisplay = {};
  stuffToDisplay.time = (new Date(Date.now())).toLocaleTimeString('en-US');
  return stuffToDisplay;
}

app.get('/time', function(req,res){
  res.render('time', genContext());
});

function genNum(){
  var randNum = {};
  randNum.number = Math.random();
  return randNum;
}

app.get('/number', function(req,res){
  res.render('number', genNum());
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err,req,res,next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localholst:' + app.get('port') + '; press Ctrl+c to terminate.');
});
