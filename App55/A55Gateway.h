//
//  A55Gateway.h
//  App55
//
//  Created by Tim Behrsin on 19/10/2013.
//  Copyright (c) 2013 App55 Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "A55Environment.h"
#import "A55CardCreateRequest.h"
#import "A55CardDeleteRequest.h"
#import "A55CardListRequest.h"
#import "A55UserAuthenticateRequest.h"
#import "A55UserCreateRequest.h"
#import "A55UserGetRequest.h"
#import "A55UserUpdateRequest.h"
#import "A55TransactionCreateRequest.h"
#import "A55TransactionCommitRequest.h"
#import "A55ScheduleCreateRequest.h"
#import "A55ScheduleDeleteRequest.h"
#import "A55ScheduleGetRequest.h"
#import "A55ScheduleListRequest.h"
#import "A55ScheduleUpdateRequest.h"

@interface A55Gateway : NSObject {
    NSString *apiSecret;
}
@property (readonly) NSString *apiKey;
@property (readonly) A55Environment *environment;
@property (readonly) BOOL hasApiSecret;
@property (copy)     A55Object *data;
@property (assign)   BOOL storeAuthenticationTokens;

- (void)setAuthorizationHeader:(NSMutableURLRequest*)request;

- (id)initWithEnvironment:(A55Environment*)environment
                   apiKey:(NSString*)apiKey
                apiSecret:(NSString*)apiSecret;

+ (id)gatewayWithEnvironment:(A55Environment*)environment
                      apiKey:(NSString*)apiKey
                   apiSecret:(NSString*)apiSecret;

- (id)initWithEnvironment:(A55Environment *)environment
                   apiKey:(NSString *)apiKey;

+ (id)gatewayWithEnvironment:(A55Environment*)environment
                      apiKey:(NSString*)apiKey;

- (A55CardCreateRequest*)createCard:(A55Card*)card user:(A55User*)user;
- (A55CardDeleteRequest*)deleteCard:(A55Card*)card user:(A55User*)user;
- (A55CardListRequest*)listCards:(A55User*)user;

- (A55UserAuthenticateRequest*)authenticateUser:(A55User*)user;
- (A55UserCreateRequest*)createUser:(A55User*)user;
- (A55UserGetRequest*)getUser:(A55User*)user;
- (A55UserUpdateRequest*)updateUser:(A55User*)user;

- (A55TransactionCreateRequest*)createTransactionWithCard:(A55Card*)card
                                                     user:(A55User*)user
                                              transaction:(A55Transaction*)transaction
                                                ipAddress:(NSString*)ipAddress;
- (A55TransactionCreateRequest*)createTransactionWithCard:(A55Card*)card
                                                     user:(A55User*)user
                                              transaction:(A55Transaction*)transaction;
- (A55TransactionCreateRequest*)createTransactionWithCard:(A55Card *)card
                                              transaction:(A55Transaction *)transaction
                                                ipAddress:(NSString*)ipAddress;
- (A55TransactionCreateRequest*)createTransactionWithCard:(A55Card *)card
                                              transaction:(A55Transaction *)transaction;
- (A55TransactionCommitRequest*)commitTransaction:(A55Transaction*)transaction;

- (A55ScheduleCreateRequest*)createScheduleWithCard:(A55Card*)card
                                               user:(A55User*)user
                                        transaction:(A55Transaction*)transaction
                                           schedule:(A55Schedule*)schedule;
- (A55ScheduleDeleteRequest*)deleteScheduleWithUser:(A55User*)user
                                           schedule:(A55Schedule*)schedule;
- (A55ScheduleGetRequest*)getScheduleWithUser:(A55User*)user
                                     schedule:(A55Schedule*)schedule;
- (A55ScheduleListRequest*)listSchedules:(A55User*)user;
- (A55ScheduleListRequest*)listSchedules:(A55User*)user active:(NSNumber*)active;
- (A55ScheduleUpdateRequest*)updateScheduleWithCard:(A55Card*)card
                                               user:(A55User*)user
                                           schedule:(A55Schedule*)schedule;

- (NSString*)sign:(A55Object*)object;

@end
