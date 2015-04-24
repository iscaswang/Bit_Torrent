#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring>
#include "../peer/peer.h"


/**
 definition of this  class is used as the based class 
 for all kinds of message class definitions

*/
class AnyMsg
{
  public :
     static int int_to_char( int i , unsigned char c[4]);
     static int char_to_int ( unsigned char c[4] ) ;

     virtual int create_msg ( Peer &peer ) = 0 ;
} ;

/**
class of Hand Shake Message 

*/

class Hand_Shake_Msg : public AnyMsg 
{
  private :
	std::string _info_hash ;
	std::string  _peer_id ;
  public :
	Hand_Shake_Msg ( std::string &info_hash , std::string &peer_id )
	{
		_info_hash = info_hash ;
		_peer_id   = peer_id  ;
	}
	
	virtual int create_msg ( Peer &peer ) ;
   
} ;

/**
 class of Hearbeats Message , only creates messages with header
 sends Heartbeats just tell peers , I the sender still alive
*/

class Keep_Alive_Msg : public AnyMsg
{
  public :
	virtual int create_msg ( Peer &peer ) ;
//	virtual int process_msg  ( Peer &peer , std::string& msg ) ;
} ;

class Chock_Interested_Msg : public AnyMsg 
{
  private :
	int _type ;
  
  public :
	Chock_Interested_Msg ( int type )
	{
		_type = type ;
        }
	virtual int create_msg ( Peer &peer ) ;
//	virtual int process_msg  ( Peer &peer , std::string& msg  ) ;
} ;


class Have_Msg : public AnyMsg 
{
  private :
	int _index ;
	
  public :
	Have_Msg ( int index ) 
	{
		_index = index ;
	}
	virtual int create_msg ( Peer &peer ) ;
//	virtual int process_msg  ( Peer &peer , std::string& msg) ;
} ;

class Bit_Field_Msg : public AnyMsg 
{
 private:
	std::string _bitfield ;
 public :
	Bit_Field_Msg ( std::string& bitfield )
	{
		_bitfield = bitfield ;
        }
	
	virtual int create_msg ( Peer &peer ) ;
//	virtual int process_msg  ( Peer &peer , std::string& msg ) ;
} ;

class Request_Msg : public AnyMsg 
{
 private :
	int _index ;
	int _begin ;
	int _length ;
 public :
	Request_Msg ( int index , int begin , int length )
	{
		_index = index ;
		_begin = begin ;
		_length = length ;
	}
	
	virtual int create_msg ( Peer &peer ) ;
} ;

class Piece_Msg : public  AnyMsg 
{
  private :
	int _index ;
	int _begin ;
	std::string _block ;
	
  public :
	Piece_Msg ( int index , int begin , std::string& block )
	{
		_index = index ;
		_begin = begin ;
		_block = block ;
	}
	
	virtual int create_msg ( Peer &peer ) ;
//	virtual int process_msg  ( Peer &peer , std::string &msg ) ; 
} ;

class Cancel_Msg : public AnyMsg 
{
   private:
	int _index ;
	int _begin ;
	int _length ;
   public :
	Cancel_Msg ( int index , int begin , int length )
	{
		_index = index ;
		_begin = begin ;
		_length = length ;
	}

	virtual int create_msg ( Peer &peer ) ;
//	virtual int process_msg  ( Peer &peer , std::string&  msg );
} ;

class Port_Msg : public AnyMsg
{
 private :
	int _port ;
 public :
	Port_Msg ( int port )
        {
	    _port = port ;
	} 
	
	virtual int create_msg ( Peer &peer ) ;
//	virtual int process_msg  ( Peer &peer , std::string& msg ) ;
} ;

#endif // message.h
