-- phpMyAdmin SQL Dump
-- version 2.10.3deb1ubuntu0.1
-- http://www.phpmyadmin.net
-- 
-- Host: localhost
-- Generation Time: Mar 14, 2008 at 02:46 PM
-- Server version: 5.0.45
-- PHP Version: 5.2.3-1ubuntu6.3

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

SET AUTOCOMMIT=0;
START TRANSACTION;

-- 
-- Database: `joomla`
-- 

-- --------------------------------------------------------

-- 
-- Table structure for table `jmcp_game_crypto_keys`
-- 

CREATE TABLE IF NOT EXISTS `jmcp_game_crypto_keys` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `GameId` int(11) NOT NULL default '0',
  `IsClientSide` tinyint(1) NOT NULL,
  `IsPrivate` tinyint(1) NOT NULL,
  `CryptoKey` blob NOT NULL,
  `CreatedOn` timestamp NOT NULL default CURRENT_TIMESTAMP on update CURRENT_TIMESTAMP,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 COMMENT='Contains keys to encrypt and decrypt jmcp packets' AUTO_INCREMENT=9 ;

-- 
-- Dumping data for table `jmcp_game_crypto_keys`
-- 

INSERT INTO `jmcp_game_crypto_keys` (`id`, `GameId`, `IsClientSide`, `IsPrivate`, `CryptoKey`, `CreatedOn`) VALUES 
(5, 5, 1, 0, 0x30819f300d06092a864886f70d010101050003818d0030818902818100b7cda44ccbca5e913c512ad913a3e1446439d4cde00ed7f02676235c10fc996a0f11fe262c5b31042ccf0bbafb9ed91683ae061803440d983226a4dc7cb8c0f326129218fd030247798634ff22abe03b72ddf081c51111e72642f29ae70bed38dc75f7124e4f707066b7f7bcdbfa59359574fe4345b4883edce68964545be9170203010001, '2008-03-11 14:17:44'),
(6, 5, 0, 1, 0x30820276020100300d06092a864886f70d0101010500048202603082025c02010002818100b7cda44ccbca5e913c512ad913a3e1446439d4cde00ed7f02676235c10fc996a0f11fe262c5b31042ccf0bbafb9ed91683ae061803440d983226a4dc7cb8c0f326129218fd030247798634ff22abe03b72ddf081c51111e72642f29ae70bed38dc75f7124e4f707066b7f7bcdbfa59359574fe4345b4883edce68964545be91702030100010281804fa9f4bd4852b4fc33ed6629e206549ba4e91fdfff6dcf9009cb8875ddf2edb77742b029f16db0e80357d5d8bc3854151b0bb11e7543e8b47f801a526a485570118147fd2d10c8f3b83f36df935542a0d9515a6916021780142308f40b11059e863e011b143c96fe29b06c63375f9e9f044c1bcd3db97e5193eb13cc20b478b9024100df63afa9e1db99c18de12bf239bd7471015502de05682c07d9d3cc82c050a98c9bc4853757eb4d68aa821c41e11bf166246554369c1952e77d3550abd3e67b73024100d2a293f792a4593035b80f455cc09eb141096c02493745d5f70340183dc2022ee18fbc2066929cba6b7aeb5f6763c5c2870853c2ba6f5cb75d207723b1213acd024100a3e46d32c423eb50981945b6b72a0a4e065e2a765d9d2a00b08db59390291ddbad44a7400d5ef3320136e8286551aceff56fea330e9f7db59ca50b04a5b889850240082692633a2171f213a213b53369a0ba6b31da241c812f0aa08c57a6987d31686f0208dd981a84461272a73901df327fdc89cdf3f312ec1b8c56fd453c4d74e102400ec484c901db53f07016b0983e114c1bf48d9d4eafccb7d77896c52260d4741ef6a3f7f16af6acd73b3e076825c98c669d178a4600d96e96ce5481b4316217f6, '2008-03-11 14:17:44');

COMMIT;
