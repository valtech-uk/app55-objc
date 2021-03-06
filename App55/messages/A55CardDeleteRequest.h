//
//  A55CardDeleteRequest.h
//  App55
//
//  Created by Tim Behrsin on 20/10/2013.
//  Copyright (c) 2013 App55 Ltd. All rights reserved.
//

#import "A55Request.h"
#import "A55Response.h"
#import "A55Card.h"
#import "A55User.h"


@interface A55CardDeleteResponse : A55Response

@end

@interface A55CardDeleteRequest : A55Request
@property (copy) A55Card *card;
@property (copy) A55User *user;

- (id)initWithCard:(A55Card*)card user:(A55User*)user gateway:(A55Gateway*)gateway;
@end