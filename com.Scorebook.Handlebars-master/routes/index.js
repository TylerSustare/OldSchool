var express = require('express');
var router = express.Router();
var session = require('express-session');
var uuid = require('node-uuid');

// We need this to build our post string
var querystring = require('querystring');
var http = require('http');
var fs = require('fs');
var request = require("request")

/* GET home page. */
router.get('/', function(req, res, next) {
  var context = { title: 'Create A Profile' };
  res.render('index', context );
});

/* handle form sent via post from index */
router.post('/thankyou', function(req,res, next) {
  var context = req.body; // initialize context to the data from the form
  // guid for userkey
  context.UserKey =uuid.v4();
  var contextStr = JSON.stringify(context)
  var postThisData = {
    "operation": "create",
    "tableName": "Sustare",
    "payload": {"TableName": "t", "Item": {}}
  };
  // postThisData.payload.Item = context; // set up body of request
  postThisData.payload.Item.UserKey = context.UserKey; // set up body of request
  postThisData.payload.Item.UserName = context.UserName; // set up body of request
  postThisData.payload.Item.TeamName = context.TeamName  // set up body of request
  postThisData.payload.Item.Level = context.Level; // set up body of request
  postThisData.payload.Item.Role = context.Role; // set up body of request
  postThisData.payload.Item.IsSignedUp = context.IsSignedUp; // set up body of request
  console.log(postThisData);

  // request to lambda function
  request({
    "url": "https://ph038d4at3.execute-api.us-west-2.amazonaws.com/sustare_test/sustaredynamo",
    "method": "POST",
    "headers": {
      "Content-Type": "application/json"
    },
    "body": JSON.stringify(postThisData)
  }, handlePost);
  function handlePost(err, response, body) {
    if (!err && response.statusCode < 400) {
      context = postThisData;
      res.render('thankyou', context);
    } else {
      console.log(err);
      console.log(response.statusCode);
      context.awsResponse = body;
      console.log(context.awsResponse);
    }
  }
});

/* GET list page. */
router.get('/list', function(req, res, next) {
  var context = { title: 'View the list' };
  var postThisData = {
    "operation": "list",
    "tableName": "Sustare",
    "payload": {"TableName": "Sustare"}
  };

  // request to lambda function
  request({
    "url": "https://ph038d4at3.execute-api.us-west-2.amazonaws.com/sustare_test/sustaredynamo",
    "method": "POST",
    "headers": {
      "Content-Type": "application/json"
    },
    "body": JSON.stringify(postThisData)
  }, handlePost);
  function handlePost(err, response, body) {
    if (!err && response.statusCode < 400) {
      context.list = JSON.parse(response.body);
      // console.log(context.list['Items'][0]);
      res.render('list',context.list);
    } else {
      console.log(err);
      console.log(response.statusCode);
      context.awsResponse = body;
      console.log(context.awsResponse);
    }
  }
});
module.exports = router;


