#if !defined(RESIP_APPDIALOGSET_HXX)
#define RESIP_APPDIALOGSET_HXX

#include "resiprocate/dum/Handles.hxx"
#include "resiprocate/dum/Handled.hxx"
#include "resiprocate/dum/DialogSet.hxx"
#include "resiprocate/dum/DialogSetId.hxx"
#include "resiprocate/dum/UserProfile.hxx"

namespace resip
{

class SipMessage;
class DialogUsageManager;

class AppDialogSet : public Handled
{
   public:
      AppDialogSet(DialogUsageManager& dum);

      // by default, calls the destructor. application can override this if it
      // wants to manage memory on its own. 
      virtual void destroy();

      virtual void end();

      virtual UserProfile* getUserProfile();

      virtual AppDialog* createAppDialog(const SipMessage&);

      AppDialogSetHandle getHandle();
      DialogSetId getDialogSetId();

      virtual std::ostream& dump(std::ostream& strm) const;

   protected:
      DialogUsageManager& mDum;      
      virtual ~AppDialogSet();
      // This is called by the DialogUsageManager to select an userProfile to assign to a UAS DialogSet.
      // The application should not call this directly, but should override it, in order to assign 
      // an userProfile other than the MasterProfile
      virtual UserProfile* selectUASUserProfile(const SipMessage&); 

   private:
      friend class DialogUsageManager;
      DialogSet* mDialogSet;
};

}

#endif

/* ====================================================================
 * The Vovida Software License, Version 1.0 
 * 
 * Copyright (c) 2000 Vovida Networks, Inc.  All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * 3. The names "VOCAL", "Vovida Open Communication Application Library",
 *    and "Vovida Open Communication Application Library (VOCAL)" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact vocal@vovida.org.
 *
 * 4. Products derived from this software may not be called "VOCAL", nor
 *    may "VOCAL" appear in their name, without prior written
 *    permission of Vovida Networks, Inc.
 * 
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL VOVIDA
 * NETWORKS, INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT DAMAGES
 * IN EXCESS OF $1,000, NOR FOR ANY INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 * ====================================================================
 * 
 * This software consists of voluntary contributions made by Vovida
 * Networks, Inc. and many individuals on behalf of Vovida Networks,
 * Inc.  For more information on Vovida Networks, Inc., please see
 * <http://www.vovida.org/>.
 *
 */
