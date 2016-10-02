var express = require('express');
var router = express.Router();
var uuid = require('node-uuid');

// still need this stuff for posting
var querystring = require('querystring');
var http = require('http');
var fs = require('fs');
var request = require("request");

/* 
 * GET users list. 
 * returns json object of table contents
 */
router.get('/', function(req, res, next) {
  var context = {};
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
  }, handleGet);
  function handleGet(err, response, body) {
    if (!err && response.statusCode < 400) {
      context.list = JSON.parse(response.body);
      // console.log(context.list['Items'][0]);
      res.send(JSON.stringify(context.list));
    } else {
      res.send(JSON.stringify(response.statusCode));
    }
  }
});

/* 
 * POST to add user
 */
router.post('/', function(req, res, next) {
  var context = req.body; // initialize context to the data from the form
  // GUID for userkey
  context.UserKey =uuid.v4();
  var postThisData = {
    "operation": "create",
    "tableName": "Sustare",
    "payload": {"TableName": "Sustare", "Item": {}}
  };
  // postThisData.payload.Item = context; // set up body of request
  postThisData.payload.Item.UserKey = context.UserKey // set up body of request
  postThisData.payload.Item.UserName = context.UserName; // set up body of request
  postThisData.payload.Item.TeamName = context.TeamName  // set up body of request
  postThisData.payload.Item.Level = context.Level; // set up body of request
  postThisData.payload.Item.Role = context.Role; // set up body of request
  postThisData.payload.Item.IsSignedUp = context.IsSignedUp; // set up body of request

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
      res.send(JSON.stringify(response.statusCode));
    } else {
      console.log(err);
      res.send(JSON.stringify(response.statusCode));
    }
  }
});

router.put('/', function(req, res, next) {
  var context = req.body; // initialize context to the data from the form
  var updateUserKey = context.UserKey
  var updateUserName = context.UserName;
  var updateTeamName = context.TeamName;
  var updateIsSignedUp = context.IsSignedUp;
  var postThisData = {
    "operation": "update",
    "tableName":"Sustare",
    "payload":{
      "TableName":"Sustare",
      "Key":{
        "UserKey": updateUserKey
      },
      "UpdateExpression": "set UserName = :u, TeamName = :t, IsSignedUp=:i",
      "ExpressionAttributeValues":{
        ":u": updateUserName,
        ":t": updateTeamName,
        ":i": updateIsSignedUp
      }
    }
  };

  // request to lambda function
  request({
    "url": "https://ph038d4at3.execute-api.us-west-2.amazonaws.com/sustare_test/sustaredynamo",
    "method": "POST",
    "headers": {
      "Content-Type": "application/json"
    },
    "body": JSON.stringify(postThisData)
  }, handlePut);
  function handlePut(err, response, body) {
    if (!err && response.statusCode < 400) {
      res.send(JSON.stringify(response.statusCode));
    } else {
      console.log(err);
      res.send(JSON.stringify(response.statusCode));
    }
  }
});

/*
* DELETE request
*/
router.delete('/', function(req, res, next) {
  var context = req.body; // initialize context to the data from the form
  var deleteUserKey = context.UserKey
  var postThisData = {
    "operation": "delete",
    "tableName":"Sustare",
    "payload":{
      "TableName":"Sustare",
      "Key":{
        "UserKey": deleteUserKey
      }
    }
  };

  // request to lambda function
  request({
    "url": "https://ph038d4at3.execute-api.us-west-2.amazonaws.com/sustare_test/sustaredynamo",
    "method": "POST",
    "headers": {
      "Content-Type": "application/json"
    },
    "body": JSON.stringify(postThisData)
  }, handleDelete);
  function handleDelete(err, response, body) {
    if (!err && response.statusCode < 400) {
      res.send(JSON.stringify(response.statusCode));
    } else {
      console.log(err);
      res.send(JSON.stringify(response.statusCode));
    }
  }
});

module.exports = router;
