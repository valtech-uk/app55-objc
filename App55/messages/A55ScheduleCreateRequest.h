//
//  A55ScheduleCreateRequest.h
//  App55
//
//  Created by Tim Behrsin on 20/10/2013.
//  Copyright (c) 2013 App55 Ltd. All rights reserved.
//

#import "A55Request.h"
#import "A55Response.h"
#import "A55User.h"
#import "A55Transaction.h"
#import "A55Card.h"
#import "A55Schedule.h"

@interface A55ScheduleCreateResponse : A55Response
@property (copy) A55Card *card;
@property (copy) A55Transaction *transaction;
@property (copy) A55Schedule *schedule;
@end

@interface A55ScheduleCreateRequest : A55Request
@property (copy) A55Card *card;
@property (copy) A55User *user;
@property (copy) A55Transaction *transaction;
@property (copy) A55Schedule *schedule;


- (id)initWithCard:(A55Card*)card
              user:(A55User*)user
       transaction:(A55Transaction*)transaction
          schedule:(A55Schedule*)schedule
           gateway:(A55Gateway*)gateway;
@end