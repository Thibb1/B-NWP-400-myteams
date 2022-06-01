/*
** EPITECH PROJECT, 2022
** server
** File description:
** subscription
*/

#include "server.h"

void free_subscriptions(subscription_t *list)
{
    subscription_t *tmp = list;
    subscription_t *tmp2 = NULL;

    while (tmp) {
        tmp2 = tmp->next;
        DESTROY(tmp->uuid);
        DESTROY(tmp);
        tmp = tmp2;
    }
}

void add_subscription(int i, char *uuid)
{
    subscription_t *subscription = calloc(1, sizeof(subscription_t));
    user_t *user = get_user(C_UUID);
    subscription->uuid = strdup(uuid);
    subscription->next = user->subscriptions;
    user->subscriptions = subscription;
    server_event_user_subscribed(uuid, C_UUID);
}

bool is_subscribed(int i, char *channel_uuid)
{
    user_t *user = get_user(C_UUID);
    if (!user)
        return false;
    subscription_t *subscription = user->subscriptions;
    while (subscription) {
        if (!strcmp(subscription->uuid, channel_uuid))
            return true;
        subscription = subscription->next;
    }
    return false;
}

void conditionnal(subscription_t *s, subscription_t *p, user_t *u)
{
    if (p)
        p->next = s->next;
    else
        u->subscriptions = s->next;
}

void remove_subscription(int i, char *uuid)
{
    user_t *user = get_user(C_UUID);
    subscription_t *subscription = user->subscriptions;
    subscription_t *prev = NULL;
    while (subscription) {
        if (!strcmp(subscription->uuid, uuid)) {
            conditionnal(subscription, prev, user);
            server_event_user_unsubscribed(uuid, C_UUID);
            DESTROY(subscription->uuid);
            DESTROY(subscription);
            return;
        }
        prev = subscription;
        subscription = subscription->next;
    }
}
