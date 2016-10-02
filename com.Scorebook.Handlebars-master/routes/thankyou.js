/**
 * Created by tyler.sustare on 7/9/2016.
 */
var express = require('express');
var router = express.Router();
var session = require('express-session');
var AWS = require("aws-sdk");
var DOC = require("dynamo-doc");

/* Get dynamo data */
router.get('/thankyou', function(req,res, next) {
    res.render('thankyou', context);
});
module.exports = router;

